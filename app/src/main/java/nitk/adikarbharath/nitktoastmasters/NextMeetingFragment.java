package nitk.adikarbharath.nitktoastmasters;

import android.content.Context;
import android.content.DialogInterface;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.design.widget.Snackbar;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class NextMeetingFragment extends Fragment {

    // Standard variables to connect to the Firebase Database.
    DatabaseReference dbRef = FirebaseDatabase.getInstance().getReference();
    private Toast toast;

    // SimpleAdapter variable declared globally for different functions.
    private SimpleAdapter sa;

    // Checker variable for when the fragment is created. Replace in future.
    private int onCreate = 0;

    // Descriptions of each role stored globally
    private List<String> next_meeting_descriptions;
    private List<String> next_meeting_roles;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        final View v = inflater.inflate(R.layout.fragment_next_meeting_list_view, container, false);
        final ListView listView = v.findViewById(R.id.fragment_next_meeting_list_view);
        final SwipeRefreshLayout swipeRefreshLayout = v.findViewById(R.id.swipe_container);

        if (getActivity()!=null)
            toast = Toast.makeText(getActivity(), null, Toast.LENGTH_SHORT);

        swipeRefreshLayout.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                swipeRefreshLayout.setRefreshing(true);
                // refreshing code:
                stopRefreshing(v);
                refreshView();
            }
        });

        swipeRefreshLayout.setColorSchemeColors(getResources().getColor(R.color.colorAccent));


        if (!isNetworkAvailable()){
            toast.setText("You are not connected to the Internet. " +
                    "Please reconnect and refresh the page by swiping down.");
            toast.show();
            swipeRefreshLayout.setRefreshing(false);
        }

        else {
            swipeRefreshLayout.setRefreshing(true);
            Query q = dbRef.child("Roles").orderByChild("order");
            q.addValueEventListener(new ValueEventListener() {

                @Override
                public void onDataChange(@NonNull DataSnapshot dataSnapshot) {

                    if(onCreate!=0){
                        toast.setText("Next Meeting Details updated.");
                        toast.show();
                    }
                    if (sa!=null){
                        sa.notifyDataSetChanged();
                        listView.invalidateViews();
                    }
                    populateListView(v,dataSnapshot);

                    if(onCreate==0)
                        swipeRefreshLayout.setRefreshing(false);
                    else
                        stopRefreshing(v);

                    onCreate=1;
                    }

                @Override
                public void onCancelled(@NonNull DatabaseError databaseError) {
                    stopRefreshing(v);
                    toast.setText("Failed to load the meeting details. " +
                            "Please refresh the page by swiping down.");
                    toast.show();
                }
            });
        }

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                AlertDialog.Builder builder;
                builder = new AlertDialog.Builder(getActivity());
                builder.setTitle(next_meeting_roles.get(position))
                        .setMessage(next_meeting_descriptions.get(position))
                        .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                            }
                        })
//                        .setIcon(android.R.drawable.ic_dialog_info)
                        .show();
            }
        });


        return v;
    }

    // Refresh the View.
    private void refreshView(){
        if(getActivity()!=null){
            FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
            Fragment fragment = fragmentManager.findFragmentById(R.id.fragment_container);
            if(fragment instanceof NextMeetingFragment) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                    fragmentManager.beginTransaction().detach(fragment).commitNow();
                    fragmentManager.beginTransaction().attach(fragment).commitNow();
                } else {
                    fragmentManager.beginTransaction().detach(fragment).commit();
                    fragmentManager.beginTransaction().attach(fragment).commit();
                }
            }
        }
    }

    // Populate the ListView dynamically.
    private void populateListView(final View v, @NonNull DataSnapshot dataSnapshot){
        final ListView listView = v.findViewById(R.id.fragment_next_meeting_list_view);
        final ArrayList<HashMap<String, String>> list = new ArrayList<>();

        //Using an array list defined already to populate ListView
        List<String> MeetingRoles = displayRoles(dataSnapshot);
        HashMap<String, String> item;
        int i;
        int n = MeetingRoles.size();
        for (i = 0; i < (n / 2); ++i) {
            item = new HashMap<>();
            item.put("roles", MeetingRoles.get(i));
            item.put("people", MeetingRoles.get((n / 2) + i));
            list.add(item);
        }

        //Use an Adapter to link data to Views
        if (getActivity()!=null) {
            sa = new SimpleAdapter(getActivity(), list, R.layout.fragment_next_meeting,
                    new String[]{"roles", "people"},
                    new int[]{R.id.line_a, R.id.line_b});
            //Link the Adapter to the list
            listView.setAdapter(sa);
        }
    }

    // Stop the refreshing animation with a delay.
    private void stopRefreshing(View v){
        final SwipeRefreshLayout swipeRefreshLayout = v.findViewById(R.id.swipe_container);
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                swipeRefreshLayout.setRefreshing(false);
            }
        },1000);
    }

    // Populate the List required for the ListView.
    private List<String> displayRoles(DataSnapshot dataSnapshot) {
        String people_add,people_check,role_description = "";
        next_meeting_roles = new ArrayList<>();
        List<String> next_meeting_people = new ArrayList<>();
        next_meeting_descriptions = new ArrayList<>();

        Iterable<DataSnapshot> it = dataSnapshot.getChildren();
        Iterable<DataSnapshot> people_iterator;

        for (DataSnapshot i : it) {
            next_meeting_roles.add(i.getKey());
            people_add = "";
            people_iterator = i.getChildren();
            for (DataSnapshot j: people_iterator) {
                people_check = j.getKey();
                switch(people_check){
                    case "Name": people_add = j.getValue().toString(); break;
                    case "description": role_description = j.getValue().toString(); break;
                    case "Speaker": people_add = j.getValue().toString() + " : " + people_add; break;
                    case "Project": people_add = j.getValue().toString() + " : " + people_add; break;
                    case "Evaluator": people_add = j.getValue().toString(); break;
                }
            }
            next_meeting_people.add(people_add);
            next_meeting_descriptions.add(role_description);
        }
        next_meeting_roles.addAll(next_meeting_people);
        return next_meeting_roles;
    }

    // Check for Internet connectivity.
    private boolean isNetworkAvailable() {
        ConnectivityManager connectivityManager = null;
        if (getActivity()!=null)
            connectivityManager = (ConnectivityManager) getActivity().getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }

}
