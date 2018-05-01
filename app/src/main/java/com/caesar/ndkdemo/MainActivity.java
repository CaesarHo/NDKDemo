package com.caesar.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    //export PATH=${PATH}:/Users/wade/Library/Android/android-ndk-r14b

    //生成.H文件命令------>javah -d ../jni -jni com.caesar.ndkdemo.MainActivity

    //生成so文件命令------>android-ndk-r14b wade$ ndk-build -C /Users/wade/Desktop/StudioWork/NDKDemo/app/src/main/jni


    // Used to load the 'native-lib' library on application startup.
    // 加载动态库，这里对应 Android.mk 里的 LOCAL_MODULE := NDKDemo
    static {
        System.loadLibrary("NDKDemo");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public native int intFromJNI();

    public native long LongFromJNI();

    public native char aCharFromJNI();
}
