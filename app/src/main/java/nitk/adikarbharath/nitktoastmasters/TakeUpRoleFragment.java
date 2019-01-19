package nitk.adikarbharath.nitktoastmasters;

import android.app.ActionBar;
import android.content.Context;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

import java.text.DateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.jar.Attributes;

public class TakeUpRoleFragment extends Fragment{

    // Standard variables to connect to the Firebase Database.
    private DatabaseReference dbRef = FirebaseDatabase.getInstance().getReference().child("Roles");
    private DatabaseReference dbRef_updateStack = FirebaseDatabase.getInstance().getReference().child("UpdateStack");
    private FirebaseAuth mAuth = FirebaseAuth.getInstance();
//    private DatabaseReference connectedRef = FirebaseDatabase.getInstance().getReference(".info/connected");
//    private boolean connectedStatus = true;

    // To make sure toasts are not created when another fragment is in view.
    private Toast toast;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_take_up_role,container,false);

        if (getActivity()!=null)
            toast = Toast.makeText(getActivity(), null, Toast.LENGTH_SHORT);

        updateUI(mAuth.getCurrentUser(),v);

        final EditText editText_RoleName = v.findViewById(R.id.editText_RoleName);
        final SharedPreferences sharedPref = this.getActivity().getSharedPreferences("userInfo", Context.MODE_PRIVATE);
        final String name = sharedPref.getString("username","");
        editText_RoleName.setText(name);

        final EditText editText_RoleAdditional = v.findViewById(R.id.editText_RoleAdditional);
        editText_RoleAdditional.setVisibility(View.INVISIBLE);

        //initialize our spinner
        final Spinner spinner = v.findViewById(R.id.spinner_role);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(getActivity(),
                R.array.roles_array,android.R.layout.simple_spinner_dropdown_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String select = parent.getItemAtPosition(position).toString();
                switch (select) {
                    case "TMOD": case "Speaker 1": case "Speaker 2": case "Speaker 3":
                        editText_RoleAdditional.setVisibility(View.VISIBLE);break;
                    default:
                        editText_RoleAdditional.setVisibility(View.INVISIBLE);
                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });

//        connectedRef.addValueEventListener(new ValueEventListener() {
//            @Override
//            public void onDataChange(@NonNull DataSnapshot snapshot) {
//                boolean connected = snapshot.getValue(Boolean.class);
//                if (connected) {
//                    connectedStatus = true;
//                } else {
//                    connectedStatus = false;
//                }
//            }
//
//            @Override
//            public void onCancelled(@NonNull DatabaseError error) {
//                toast.setText("Unable to check your Internet connection.");
//                toast.show();
//            }
//        });

        Button button_take_up_role = v.findViewById(R.id.button_take_up_role);

        button_take_up_role.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String selection = spinner.getSelectedItem().toString();
                String role_name = editText_RoleName.getText().toString();
                String role_addi = editText_RoleAdditional.getText().toString();
                String roles_array[] = getResources().getStringArray(R.array.roles_array);
                String select_a_role = roles_array[0];

                if (role_name.equals("")){
                    toast.setText("Please enter a valid name.\n" +
                            "It is advisable to prefix it with TM");
                    toast.show();
                }
                else if (selection.equals(select_a_role)){
                    toast.setText("Please select a role.");
                    toast.show();
                }
                else if ((editText_RoleAdditional.isShown()) && (role_addi.equals(""))){
                    toast.setText("Please fill in the additional field.");
                    toast.show();
                }
                else if (!isNetworkAvailable()){
                    toast.setText("You are not connected to the Internet. " +
                            "Please reconnect and try again.");
                    toast.show();
                }
                else {
                    registerRole(selection,role_name,role_addi);
                }
            }
        });
        return v;
    }

    // To set or update a field in the database. Also logs the field and user ID in a separate JSON tree.
    public void registerRole(String selection, String role_name, String role_addi) {

        DatabaseReference dbRef_role_name = dbRef.child(selection).child("Name");
        DatabaseReference dbRef_role_addi = null;
        switch (selection) {
            case "TMOD":
                dbRef_role_addi = dbRef.child("Theme").child("Name");
                break;
            case "Speaker 1":
                dbRef_role_name = dbRef.child("Speech 1").child("Speaker");
                dbRef_role_addi = dbRef.child("Speech 1").child("Project");
                break;
            case "Evaluator 1":
                dbRef_role_name = dbRef.child("Speech 1").child("Evaluator");
                break;
            case "Speaker 2":
                dbRef_role_name = dbRef.child("Speech 2").child("Speaker");
                dbRef_role_addi = dbRef.child("Speech 2").child("Project");
                break;
            case "Evaluator 2":
                dbRef_role_name = dbRef.child("Speech 2").child("Evaluator");
                break;
            case "Speaker 3":
                dbRef_role_name = dbRef.child("Speech 3").child("Speaker");
                dbRef_role_addi = dbRef.child("Speech 3").child("Project");
                break;
            case "Evaluator 3":
                dbRef_role_name = dbRef.child("Speech 3").child("Evaluator");
                break;
        }

        dbRef_role_name.setValue(role_name);
        if (dbRef_role_addi!=null)
            dbRef_role_addi.setValue(role_addi);

        final String updateStackChild = role_name + ":" + mAuth.getCurrentUser().getEmail() + ":" + selection;

        String currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());

        dbRef_updateStack.child(currentDateTimeString).setValue(updateStackChild);

        Toast.makeText(getActivity(), "You've now taken up a role for the next meeting."
                ,Toast.LENGTH_SHORT).show();
    }

    // Update the current UI based on whether the user is authenticated or not.
    private void updateUI(FirebaseUser user, View v) {
        if (user==null){
            v.findViewById(R.id.editText_RoleName).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.editText_RoleAdditional).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.spinner_role).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.textView_role_alert).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.button_take_up_role).setVisibility(View.INVISIBLE);

            v.findViewById(R.id.textView_role_not_logged_in).setVisibility(View.VISIBLE);
            return;
        }
        v.findViewById(R.id.editText_RoleName).setVisibility(View.VISIBLE);
        v.findViewById(R.id.editText_RoleAdditional).setVisibility(View.VISIBLE);
        v.findViewById(R.id.spinner_role).setVisibility(View.VISIBLE);
        v.findViewById(R.id.textView_role_alert).setVisibility(View.VISIBLE);
        v.findViewById(R.id.button_take_up_role).setVisibility(View.VISIBLE);

        v.findViewById(R.id.textView_role_not_logged_in).setVisibility(View.INVISIBLE);
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
