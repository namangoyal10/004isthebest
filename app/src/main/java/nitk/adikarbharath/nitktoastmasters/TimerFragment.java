package nitk.adikarbharath.nitktoastmasters;

import android.app.ActionBar;
import android.os.Bundle;
import android.os.Handler;
import android.os.SystemClock;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.NumberPicker;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Arrays;
import java.util.List;

import static java.util.Locale.US;

public class TimerFragment extends Fragment{

    // To-do: Clean up code and make it readable!!

    TextView timer;
    Button start, pause, reset;
    long MillisecondTime, StartTime, TimeBuff, UpdateTime = 0L ;
    Handler handler;
    int Seconds, Minutes, MilliSeconds,totalSeconds;

    double Minutes_Green,Minutes_Yellow,Minutes_Red;

    View v;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        v = inflater.inflate(R.layout.fragment_timer,container,false);

        final NumberPicker numberPicker1 = v.findViewById(R.id.numberPicker1);
        final NumberPicker numberPicker2 = v.findViewById(R.id.numberPicker2);
        final Spinner spinner = v.findViewById(R.id.spinner_timer);

        numberPicker1.setMinValue(0);
        numberPicker2.setMinValue(1);
        numberPicker1.setMaxValue(119);
        numberPicker2.setMaxValue(120);
        numberPicker1.setOnValueChangedListener(new NumberPicker.OnValueChangeListener() {
            @Override
            public void onValueChange(NumberPicker picker, int oldVal, int newVal) {
                int value = numberPicker1.getValue() + 1;
                numberPicker2.setMinValue(value);
                spinner.setSelection(4,true);
            }
        });

        numberPicker2.setOnValueChangedListener(new NumberPicker.OnValueChangeListener() {
            @Override
            public void onValueChange(NumberPicker picker, int oldVal, int newVal) {
                spinner.setSelection(4,true);
            }
        });


        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(getActivity(),
                R.array.timer_array,android.R.layout.simple_spinner_dropdown_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {

            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String select = parent.getItemAtPosition(position).toString();
                final String[] timer_array = getResources().getStringArray(R.array.timer_array);

                // Not using select, as it doesn't have the constants on runtime (works with constants)

                if (select.equals(timer_array[0])){
                    numberPicker1.setValue(4);
                    numberPicker2.setValue(6);
                }
                else if (select.equals(timer_array[1])){
                    numberPicker1.setValue(5);
                    numberPicker2.setValue(7);
                }

                else if (select.equals(timer_array[2])){
                    numberPicker1.setValue(1);
                    numberPicker2.setValue(2);
                }
                else if (select.equals(timer_array[3])){
                    numberPicker1.setValue(2);
                    numberPicker2.setValue(3);
                }
                else {
                    numberPicker1.setValue(0);
                    numberPicker2.setValue(1);
                }

            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });


        timer = v.findViewById(R.id.textView_timer);
        start = v.findViewById(R.id.button_start);
        pause = v.findViewById(R.id.button_pause);
        reset = v.findViewById(R.id.button_reset);

        handler = new Handler();

        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Minutes_Green = numberPicker1.getValue();
                Minutes_Red = numberPicker2.getValue();
                Minutes_Yellow=(Minutes_Red + Minutes_Green)/2;

                StartTime = SystemClock.uptimeMillis();
                handler.postDelayed(runnable, 0);

                updateUI(v,View.INVISIBLE);
            }
        });

        pause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                TimeBuff += MillisecondTime;
                handler.removeCallbacks(runnable);

                updateUI(v,View.VISIBLE);
//                reset.setEnabled(true);
            }
        });

        reset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                MillisecondTime = 0L ;
                StartTime = 0L ;
                TimeBuff = 0L ;
                UpdateTime = 0L ;
                Seconds = 0 ;
                Minutes = 0 ;
                MilliSeconds = 0 ;
                timer.setText("00:00");
                v.setBackgroundColor(ContextCompat.getColor(getActivity(), android.R.color.white));
            }
        });

        return v;
    }

    private void updateUI(View v, int visibility){

        start = v.findViewById(R.id.button_start);
        reset = v.findViewById(R.id.button_reset);
        final NumberPicker numberPicker1 = v.findViewById(R.id.numberPicker1);
        final NumberPicker numberPicker2 = v.findViewById(R.id.numberPicker2);
        final Spinner spinner = v.findViewById(R.id.spinner_timer);

        start.setVisibility(visibility);
        reset.setVisibility(visibility);
        spinner.setVisibility(visibility);
        numberPicker1.setVisibility(visibility);
        numberPicker2.setVisibility(visibility);

    }


    Runnable runnable = new Runnable() {

        public void run() {

            MillisecondTime = SystemClock.uptimeMillis() - StartTime;
            UpdateTime = TimeBuff + MillisecondTime;

            totalSeconds = (int) (UpdateTime / 1000);
            Minutes = totalSeconds / 60;
            Seconds = totalSeconds % 60;

            String timer_text = "" + String.format(US,"%02d", Minutes) + ":" +
                    String.format(US,"%02d", Seconds);

            timer.setText(timer_text);

            // To set the background
            if (totalSeconds>=(Minutes_Red*60))
                v.setBackgroundColor(ContextCompat.getColor(getActivity(), R.color.colorRed));

            else if (totalSeconds>=(Minutes_Yellow*60))
                v.setBackgroundColor(ContextCompat.getColor(getActivity(), R.color.colorYellow));

            else if (totalSeconds>=(Minutes_Green*60))
                v.setBackgroundColor(ContextCompat.getColor(getActivity(), R.color.colorGreen));

            handler.postDelayed(this, 0);
        }

    };
}
