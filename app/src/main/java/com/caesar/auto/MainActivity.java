package com.caesar.auto;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.caesar.auto.loads.PagingLoadActivity;
import com.caesar.auto.natives.NativeListener;
import com.caesar.auto.natives.NativeTest;

public class MainActivity extends AppCompatActivity implements NativeListener{

    //export PATH=${PATH}:/Users/wade/Library/Android/android-ndk-r14b

    //生成.H文件命令------>javah -d ../jni -jni MainActivity


    //生成so文件命令------>android-ndk-r14b wade$ ndk-build -C /Users/wade/Desktop/StudioWork/T-Auto/app/src/main/jni


    // Used to load the 'native-lib' library on application startup.
    // 加载动态库，这里对应 Android.mk 里的 LOCAL_MODULE := Auto
    static {
        System.loadLibrary("Auto");
    }

    private Context context;
    public NativeListener nativeListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.context = this;
        nativeListener = this;
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeTest.getInstance().testCycle());

        //初始化两个ImageView
        ImageView iv1 = (ImageView) findViewById(R.id.img1);
        iv1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(context, PagingLoadActivity.class);
                startActivity(intent);
                nativeListener.onTest1();
                nativeListener.onTest2();
            }
        });
        ImageView iv2 = (ImageView) findViewById(R.id.img2);

        //iv1设置图片
        iv1.setImageResource(R.mipmap.ic_launcher_round);
        //生成bitmap对象
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher_round);
        //调用native方法，传入Bitmap对象，对Bitmap进行高斯迷糊处理
        NativeTest.getInstance().testGaussBlur(bitmap);
        //把Bitmap对象设置给iv2
        iv2.setImageBitmap(bitmap);

    }

    @Override
    public void onTest1() {
        Log.d("KKK","TEST1");
    }

    @Override
    public void onTest2() {
        Log.d("KKK","TEST2");
    }
}
