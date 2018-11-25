package com.caesar.auto;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.AppCompatButton;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.caesar.auto.datastructure.Structure;
import com.caesar.auto.ftp.FtpActivity;
import com.caesar.auto.loads.PagingLoadActivity;
import com.caesar.auto.natives.NativeListener;
import com.caesar.auto.natives.NativeTest;
import com.caesar.auto.threads.Threads;

public class MainActivity extends AppCompatActivity implements NativeListener, View.OnClickListener {

    //export PATH=${PATH}:/Users/wade/Library/Android/android-ndk-r14b

    //生成.H文件命令------>javah -d ../jni -jni MainActivity


    //生成so文件命令------>android-ndk-r14b wade$ ndk-build -C /Users/wade/Desktop/StudioWork/T-Auto/app/src/main/jni


    // Used to load the 'native-lib' library on application startup.
    // 加载动态库，这里对应 Android.mk 里的 LOCAL_MODULE := Auto
    static {
        System.loadLibrary("Auto");
    }

    private final static String TAG = "MainActivity";
    private Context context;
    public NativeListener nativeListener;
    private Structure structure;
    private Threads threads;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.context = this;
        nativeListener = this;
        threads = Threads.getInstance();
        threads.initThread();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeTest.getInstance().testCycle());

        //初始化两个ImageView
        ImageView iv1 = (ImageView) findViewById(R.id.img1);
        iv1.setOnClickListener(this);


        ImageView iv2 = (ImageView) findViewById(R.id.img2);
        iv2.setOnClickListener(this);

        //iv1设置图片
        iv1.setImageResource(R.mipmap.ic_launcher_round);
        //生成bitmap对象
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher_round);
        //调用native方法，传入Bitmap对象，对Bitmap进行高斯迷糊处理
        NativeTest.getInstance().testGaussBlur(bitmap);
        //把Bitmap对象设置给iv2
        iv2.setImageBitmap(bitmap);

        AppCompatButton appCompatButton1 = findViewById(R.id.btn_1);
        appCompatButton1.setOnClickListener(this);
        AppCompatButton appCompatButton2 = findViewById(R.id.btn_2);
        appCompatButton2.setOnClickListener(this);
        AppCompatButton appCompatButton3 = findViewById(R.id.btn_3);
        appCompatButton3.setOnClickListener(this);
        AppCompatButton appCompatButton4 = findViewById(R.id.btn_4);
        appCompatButton4.setOnClickListener(this);
        AppCompatButton appCompatButton5 = findViewById(R.id.btn_5);
        appCompatButton5.setOnClickListener(this);
        AppCompatButton appCompatButton6 = findViewById(R.id.btn_6);
        appCompatButton6.setOnClickListener(this);

        AppCompatButton appCompatButton10 = findViewById(R.id.btn_10);
        appCompatButton10.setOnClickListener(this);
        AppCompatButton appCompatButton20 = findViewById(R.id.btn_20);
        appCompatButton20.setOnClickListener(this);
        AppCompatButton appCompatButton30 = findViewById(R.id.btn_30);
        appCompatButton30.setOnClickListener(this);
        AppCompatButton appCompatButton40 = findViewById(R.id.btn_40);
        appCompatButton40.setOnClickListener(this);
        AppCompatButton appCompatButton50 = findViewById(R.id.btn_50);
        appCompatButton50.setOnClickListener(this);
        AppCompatButton appCompatButton60 = findViewById(R.id.btn_60);
        appCompatButton60.setOnClickListener(this);
        AppCompatButton appCompatButton70 = findViewById(R.id.btn_70);
        appCompatButton70.setOnClickListener(this);

        structure = Structure.getInstance();
        structure.DataType();
        structure.HashSetDemo();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.img1:
                Intent intent = new Intent();
                intent.setClass(context, PagingLoadActivity.class);
                startActivity(intent);
                nativeListener.onTest1();
                nativeListener.onTest2();
                break;
            case R.id.img2:
                Intent intent2 = new Intent();
                intent2.setClass(context, FtpActivity.class);
                startActivity(intent2);
                break;
            case R.id.btn_1:
                threads.startBase();
                break;
            case R.id.btn_2:
                threads.startFixed();
                break;
            case R.id.btn_3:
                threads.startCached();
                break;
            case R.id.btn_4:
                threads.startSingle();
                break;
            case R.id.btn_5:
                threads.startSchedule();
                break;
            case R.id.btn_6:
                threads.startPriority();
                break;


            case R.id.btn_10://插入排序
                structure.sortInsert(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_20://选择排序
                structure.sortSelect(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_30:
                structure.sortBubble(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_40:
                structure.sortQuick(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_50:
                structure.sortMerge(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_60:
                structure.sortShell(new int[]{1, 32, 4, 5, 7, 2, 90});
                break;
            case R.id.btn_70:
                structure.sortHeap(new int[]{12,23,14,45,36,78,21,222,4432});
                break;
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        threads.closeThreads();
        Log.d(TAG, "onDestroy");
    }

    @Override
    public void onTest1() {
        Log.d("KKK", "TEST1");
    }

    @Override
    public void onTest2() {
        Log.d("KKK", "TEST2");
    }
}
