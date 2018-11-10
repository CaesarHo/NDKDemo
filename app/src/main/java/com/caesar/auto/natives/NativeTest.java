package com.caesar.auto.natives;

import android.graphics.Bitmap;

public class NativeTest {

    private static NativeTest cycle;

    private NativeTest(){

    }

    public synchronized static NativeTest getInstance(){
        if (cycle == null){
            synchronized (NativeTest.class){
                if (cycle == null){
                    cycle = new NativeTest();
                }
            }
        }
        return cycle;
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String testCycle();

    public native void testGaussBlur(Bitmap bitmap);
//    public native String compressBitmap(Bitmap bitmap,int w,int h,int quality,byte[] fileNameStr,boolean optimize);
}
