package nitk.adikarbharath.nitktoastmasters;


import android.app.ActionBar;
import android.os.Bundle;
import android.os.Handler;
import android.support.annotation.NonNull;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements NavigationView.OnNavigationItemSelectedListener{
    private DrawerLayout drawer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Initialize different components for the navigation bar.
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        drawer = findViewById(R.id.drawer_layout);

        final NavigationView navigationView = findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        // The last two strings as parameters were given for Accessibility support and are required
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(this, drawer, toolbar,
                        R.string.navigation_drawer_open, R.string.navigation_drawer_close);

        drawer.addDrawerListener(toggle);
        toggle.syncState();

        //Open the voting tab as default. savedInstanceState check is for screen rotation.
        if (savedInstanceState==null || getIntent()!=null) {
            selectFragment(new VotingFragment(),"Voting");
            navigationView.setCheckedItem(R.id.nav_voting);
        }

        // Change the title of the Action Bar when the Fragment is removed from view.
        getSupportFragmentManager().addOnBackStackChangedListener(new FragmentManager.OnBackStackChangedListener() {
            @Override
            public void onBackStackChanged() {
                Fragment fragment = getSupportFragmentManager().findFragmentById(R.id.fragment_container);
                String fragmentTag = "";
                if (fragment!=null)
                    fragmentTag = fragment.getTag();
                if (fragmentTag!=null)
                    setTitleFromFragment(fragmentTag);
            }
        });

    }

    // To determine the action taken when an item is selected from the Navigation Menu.
    @Override
    public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {

        drawer.closeDrawer(GravityCompat.START);
        final MenuItem menuItem2 = menuItem;

        //delay the animations of fragment.
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                switch(menuItem2.getItemId()){
                    case R.id.nav_about:
                        selectFragment(new AboutFragment(),"About");
                        break;
                    case R.id.nav_contact:
                        selectFragment(new ContactFragment(),"Contact");
                        break;
                    case R.id.nav_settings:
                        selectFragment(new SettingsFragment(),"Settings");
                        break;
                    case R.id.nav_voting:
                        selectFragment(new VotingFragment(),"Voting");
                        break;
                    case R.id.nav_next_meeting:
                        selectFragment(new NextMeetingFragment(),"Next Meeting Details");
                        break;
                    case R.id.nav_timer:
                        selectFragment(new TimerFragment(),"TM Timer");
                        break;
//                    case R.id.nav_take_up_role:
//                        try {
//                            Fragment fragment = getSupportFragmentManager().findFragmentById(R.id.fragment_next_meeting_list_view);
//                            if (fragment != null) {
//                                getSupportFragmentManager().beginTransaction().remove(fragment).commit();
//                            }
//                        }
//                        catch (Exception e) {
////                            Log.d("registerRole",e.toString());
//                        }
//                        selectFragment(new TakeUpRoleFragment(),"Take Up A Role");
//                        break;
                }
            }
        }, 250);

        return true;
    }

    // To add a new Fragment to the Activity.
    public void selectFragment(Fragment fragment, String fragmentTag) {

        getSupportFragmentManager().beginTransaction().remove(fragment).commit();
        getSupportFragmentManager().beginTransaction().
                setCustomAnimations(android.R.anim.fade_in, android.R.anim.fade_out,
                                    android.R.anim.fade_in, android.R.anim.fade_out).
                replace(R.id.fragment_container, fragment, fragmentTag).addToBackStack(fragmentTag).commit();
        setTitleFromFragment(fragmentTag);
    }

    // To set the title of the Action Bar depending on the Fragment tag.
    private void setTitleFromFragment(String fragmentTag){

        final android.support.v7.app.ActionBar actionBar = getSupportActionBar();
        if (actionBar!=null) {
            switch (fragmentTag) {
                case "About":
                    actionBar.setTitle(R.string.about);
                    break;
                case "Contact":
                    actionBar.setTitle(R.string.contact);
                    break;
                case "Settings":
                    actionBar.setTitle(R.string.settings);
                    break;
                case "Voting":
                    actionBar.setTitle(R.string.voting);
                    break;
                case "Next Meeting Details":
                    actionBar.setTitle(R.string.next_meeting);
                    break;
                case "TM Timer":
                    actionBar.setTitle(R.string.timer);
                    break;
                case "Take Up A Role":
                    actionBar.setTitle(R.string.take_up_role);
                    break;
                default:
                    actionBar.setTitle(fragmentTag);
            }
        }
    }

    // To exit or go back layers of the application.
    @Override
    public void onBackPressed(){
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        }

        int backStackEntryCount = getSupportFragmentManager().getBackStackEntryCount();
        if (backStackEntryCount==1)
            this.finishAndRemoveTask();
        else
            super.onBackPressed();
    }



}

