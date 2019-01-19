package nitk.adikarbharath.nitktoastmasters;

import android.app.ActionBar;
import android.content.Context;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.customtabs.CustomTabsIntent;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

public class VotingFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_voting,container,false);

        // Retrieve the stored username from the Settings page.
        final SharedPreferences sharedPref = this.getActivity().getSharedPreferences("userInfo", Context.MODE_PRIVATE);
        final String name = sharedPref.getString("username","");

        // Use a CustomTabsIntent.Builder to configure CustomTabsIntent.
        // Set toolbar colours and custom actions. Then finally call build();
        final CustomTabsIntent.Builder builder = new CustomTabsIntent.Builder();
        builder.setToolbarColor(ContextCompat.getColor(getActivity(), R.color.colorPrimaryDark));
        final CustomTabsIntent customTabsIntent = builder.build();

        // Set an onClickListener for each button.

        Button button_vote1 = v.findViewById(R.id.button_vote1);
        Button button_vote2 = v.findViewById(R.id.button_vote2);
        Button button_vote3 = v.findViewById(R.id.button_vote3);

        button_vote1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = "https://docs.google.com/forms/d/e/1FAIpQLSfrJ2UXE_Lq8dvJ6XvEoccaOl4d0x26xE1My_eppQRlwFGERw/viewform?usp=pp_url&entry.458003154=" + name;
                customTabsIntent.launchUrl(getActivity(), Uri.parse(url));
            }
        });

        button_vote2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = "https://docs.google.com/forms/d/e/1FAIpQLScDsyU62JCduvVP1Ou2lSmvFPbec8__pCSpbucN3UYps-BuPQ/viewform?usp=pp_url&entry.1898842101=" + name;
                customTabsIntent.launchUrl(getActivity(), Uri.parse(url));
            }
        });


        button_vote3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = "https://docs.google.com/forms/d/e/1FAIpQLSehimZvX1tRb-_67xVXRShoSC9S78nJuFq4NsOLUYQB2_JvYw/viewform?usp=pp_url&entry.1682423468=" + name;
                customTabsIntent.launchUrl(getActivity(), Uri.parse(url));
            }
        });

        return v;
    }
}
