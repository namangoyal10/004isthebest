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
import android.widget.TextView;

public class AboutFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_about,container,false);
        TextView versionName = v.findViewById(R.id.textView_versionName);
        String version = "Version " + BuildConfig.VERSION_NAME + " (beta release)";
        versionName.setText(version);

        ImageView imageView_github = v.findViewById(R.id.imageView_github);
        ImageView imageView_instagram = v.findViewById(R.id.imageView_instagram);
        ImageView imageView_linkedin = v.findViewById(R.id.imageView_linkedin);

        final String url_github = "https://github.com/lkcbharath";
        final String url_instagram = "https://www.instagram.com/bharath_adikar";
        final String url_linkedin = "https://www.linkedin.com/in/lkcbharath";

        imageView_github.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_github);
            }
        });

        imageView_instagram.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_instagram);
            }
        });

        imageView_linkedin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openInBrowser(url_linkedin);
            }
        });

        return v;
    }

    private void openInBrowser(String url) {
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        startActivity(browserIntent);
    }
}
