package nitk.adikarbharath.nitktoastmasters;

import android.app.ActionBar;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

public class ContactFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_contact,container,false);

        ImageView imageView_contact_facebook = v.findViewById(R.id.imageView_contact_facebook);
        ImageView imageView_contact_instagram = v.findViewById(R.id.imageView_contact_instagram);
        ImageView imageView_contact_website = v.findViewById(R.id.imageView_contact_website);

        final String url_facebook = "https://www.facebook.com/NITKToastmasters";
        final String url_instagram = "https://www.instagram.com/nitk_toastmasters";
        final String url_website = "https://nitktoastmasters-da7c7.firebaseapp.com/";

        imageView_contact_facebook.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_facebook);
            }
        });

        imageView_contact_instagram.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_instagram);
            }
        });

        imageView_contact_website.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_website);
            }
        });

        return v;
    }

    private void openInBrowser(String url) {
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        startActivity(browserIntent);
    }
}
