package nitk.adikarbharath.nitktoastmasters;

import android.app.ActionBar;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;


public class SettingsFragment extends Fragment {

    // Standard variable to connect to Firebase Authentication.
    private FirebaseAuth mAuth = FirebaseAuth.getInstance();

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_settings,container,false);

        updateUI(mAuth.getCurrentUser(),v);
        final SharedPreferences sharedPref = this.getActivity().
                getSharedPreferences("userInfo", Context.MODE_PRIVATE);

        //Display stored name
        final EditText editText_Name = v.findViewById(R.id.editText_Name);

        String name = sharedPref.getString("username","");
        editText_Name.setText(name);

        Button button_SetName = v.findViewById(R.id.button_SetName);

        button_SetName.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //Method to store username in a Shared Preference. Toast displayed on success
                SharedPreferences.Editor editor = sharedPref.edit();
                editor.putString("username", editText_Name.getText().toString());
                editor.apply();
                Toast.makeText(getActivity(),"Your name is now stored!",Toast.LENGTH_LONG).show();
            }
        });

        Button button_settings_login = v.findViewById(R.id.button_settings_log_in);
        //DISABLE LOGIN

//        button_settings_login.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                Intent intent = new Intent(getActivity(), LoginActivity.class);
//                startActivity(intent);
//
//
//                try {
//                    Fragment fragment = getActivity().getSupportFragmentManager().
//                            findFragmentById(R.id.fragment_next_meeting_list_view);
//                    if (fragment != null) {
//                        getActivity().getSupportFragmentManager().beginTransaction().remove(fragment).
//                                addToBackStack(null).commit();
//                    }
//                }
//                catch (Exception e) {
////                    Log.d("registerRole",e.toString());
//                }
//
//            }
//        });

        Button button_settings_log_out = v.findViewById(R.id.button_settings_log_out);
//        button_settings_log_out.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                mAuth.signOut();
//                v.invalidate();
//                if(v.getParent()!=null) {
//                    ((ViewGroup) v.getParent()).removeView(v);
//                }// <- fix
//                if (getActivity()!=null)
//                    getActivity().getSupportFragmentManager().beginTransaction().
//                            setCustomAnimations(android.R.anim.fade_in,
//                            android.R.anim.fade_out,
//                            android.R.anim.fade_in,
//                            android.R.anim.fade_out)
//                            .replace(R.id.fragment_container, new SettingsFragment())
//                            .addToBackStack(null).commit();
//
//            }
//        });

        Button button_settings_forgot_password = v.findViewById(R.id.button_settings_forgot_password);
//        button_settings_forgot_password.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                String email = mAuth.getCurrentUser().getEmail();
//                if (email == null){
//                    int i = 0;
//                }
//                else {
//                    mAuth.sendPasswordResetEmail(email)
//                            .addOnCompleteListener(new OnCompleteListener<Void>() {
//                                @Override
//                                public void onComplete(@NonNull Task<Void> task) {
//                                    if (task.isSuccessful()) {
//                                        if (getActivity() != null)
//                                            Toast.makeText(getActivity(), "A password reset " +
//                                                    "email has been sent to your email address.",
//                                                    Toast.LENGTH_LONG).show();
//                                    } else {
//                                        if (getActivity() != null)
//                                            Toast.makeText(getActivity(), "Unable to send the " +
//                                                    "password request email.", Toast.LENGTH_LONG).show();
//                                    }
//                                }
//                            });
//                }
//            }
//        });

        button_settings_login.setVisibility(View.INVISIBLE);
        button_settings_log_out.setVisibility(View.INVISIBLE);
        button_settings_forgot_password.setVisibility(View.INVISIBLE);

        return v;
    }

    // Update the current UI based on whether the user is authenticated or not.
    private void updateUI(FirebaseUser user, View v) {
        if (user==null){
            v.findViewById(R.id.button_settings_log_in).setVisibility(View.VISIBLE);
            v.findViewById(R.id.button_settings_log_out).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.button_settings_forgot_password).setVisibility(View.INVISIBLE);
            v.findViewById(R.id.textView_settings_password).setVisibility(View.INVISIBLE);
            return;
        }
        v.findViewById(R.id.button_settings_log_in).setVisibility(View.INVISIBLE);
        v.findViewById(R.id.button_settings_log_out).setVisibility(View.VISIBLE);
        v.findViewById(R.id.button_settings_forgot_password).setVisibility(View.VISIBLE);
        v.findViewById(R.id.textView_settings_password).setVisibility(View.VISIBLE);

    }
}
