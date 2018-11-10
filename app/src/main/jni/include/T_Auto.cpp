#include <jni.h>
#include <string>
#include <android/log.h>
#include "logs.h"
#include "gauss_blur.h"
#include <stdlib.h>
#include <android/bitmap.h>

#include <string.h>
#include <stdio.h>
#include <setjmp.h>
#include <math.h>
#include <stdint.h>
#include <time.h>
#include <iostream>
#include "cycle.h"
#include "Basis.h"
#include "T_Auto.h"

//extern "C" {
//#include "jpeg/android/config.h"
//#include "jpeg/jpeglib.h"
//#include "jpeg/cdjpeg.h"        /* Common decls for cjpeg/djpeg applications */
//}

extern "C"{
JNIEXPORT jstring JNICALL
Java_com_caesar_auto_natives_NativeTest_testCycle(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello C++";
    LOGV("hello verbose");
    cycle_while();
    cycle_for();
    cycle_do_while();
    cycle_nesting();
    cycle_break();
    cycle_continue();
    cycle_goto();
    basis();
    arrays();
    return env->NewStringUTF(hello.c_str());
}

/*
 * Class:     com_caesar_ndkdemo_MainActivity
 * Method:    gaussBlur  88866880  15307558137
 * Signature: ()I
 */
JNIEXPORT void JNICALL
Java_com_caesar_auto_natives_NativeTest_testGaussBlur(JNIEnv *env, jobject /* this */, jobject bmp) {
    LOGD("intFromJNI");

    AndroidBitmapInfo info = {0};//初始化BitmapInfo结构体
    int *data = NULL;//初始化Bitmap图像数据指针
    AndroidBitmap_getInfo(env, bmp, &info);
    AndroidBitmap_lockPixels(env, bmp, (void **) &data);//锁定Bitmap，并且获得指针
    /**********高斯模糊算法作对int数组进行处理***********/
    //调用gaussBlur函数，把图像数据指针、图片长宽和模糊半径传入
    gaussBlur(data, info.width, info.height, 80);
    /****************************************************/
    AndroidBitmap_unlockPixels(env, bmp);//解锁
}

//JNIEXPORT jstring JNICALL
//Java_com_caesar_auto_natives_NativeTest_compressBitmap(JNIEnv *env,
//                                                               jobject thiz,
//                                                               jobject bitmapcolor, int w,
//                                                               int h, int quality,
//                                                               jbyteArray fileNameStr,
//                                                               jboolean optimize) {
//
//    AndroidBitmapInfo infocolor;
//    BYTE *pixelscolor;
//    int ret;
//    BYTE *data;
//    BYTE *tmpdata;
//    char *fileName = jstrinTostring(env, fileNameStr);
//    if ((ret = AndroidBitmap_getInfo(env, bitmapcolor, &infocolor)) < 0) {
//        LOGE("AndroidBitmap_getInfo() failed ! error=%d", ret);
//        return env->NewStringUTF( "0");
//    }
//    if ((ret = AndroidBitmap_lockPixels(env, bitmapcolor, (void **) &pixelscolor)) < 0) {
//        LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);
//    }
//
//    BYTE r, g, b;
//    data = NULL;
//    data = (BYTE*)malloc(sizeof(w * h * 3));
//    tmpdata = data;
//    int j = 0, i = 0;
//    int color;
//    for (i = 0; i < h; i++) {
//        for (j = 0; j < w; j++) {
//            color = *((int *) pixelscolor);
//            r = ((color & 0x00FF0000) >> 16);
//            g = ((color & 0x0000FF00) >> 8);
//            b = color & 0x000000FF;
//            *data = b;
//            *(data + 1) = g;
//            *(data + 2) = r;
//            data = data + 3;
//            pixelscolor += 4;
//        }
//    }
//    AndroidBitmap_unlockPixels(env, bitmapcolor);
//    int resultCode = generateJPEG(tmpdata, w, h, quality, fileName, optimize);
//    free(tmpdata);
//    if (resultCode == 0) {
//        jstring result = env->NewStringUTF(error);
//        error = NULL;
//        return result;
//    }
//    return env->NewStringUTF("1"); //success
//}
}