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

//extern "C" {
//#include "jpeg/android/config.h"
//#include "jpeg/jpeglib.h"
//#include "jpeg/cdjpeg.h"        /* Common decls for cjpeg/djpeg applications */
//}

extern "C"
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
    return env->NewStringUTF(hello.c_str());
}



/*
 * Class:     com_caesar_ndkdemo_MainActivity
 * Method:    gaussBlur
 * Signature: ()I
 */
extern "C"
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




//#define true 1
//#define false 0
//
//typedef uint8_t BYTE;
//
//char *error;
//struct my_error_mgr {
//    struct jpeg_error_mgr pub;
//    jmp_buf setjmp_buffer;
//};
//
//typedef struct my_error_mgr *my_error_ptr;
//
//METHODDEF(void)
//my_error_exit(j_common_ptr cinfo) {
//    my_error_ptr myerr = (my_error_ptr) cinfo->err;
//    (*cinfo->err->output_message)(cinfo);
//    error = (char *) myerr->pub.jpeg_message_table[myerr->pub.msg_code];
//    LOGE("jpeg_message_table[%d]:%s", myerr->pub.msg_code,
//         myerr->pub.jpeg_message_table[myerr->pub.msg_code]);
//// LOGE("addon_message_table:%s", myerr->pub.addon_message_table);
////  LOGE("SIZEOF:%d",myerr->pub.msg_parm.i[0]);
////  LOGE("sizeof:%d",myerr->pub.msg_parm.i[1]);
//    longjmp(myerr->setjmp_buffer, 1);
//}
//
//int
//generateJPEG(BYTE *data, int w, int h, int quality, const char *outfilename, jboolean optimize) {
//    int nComponent = 3;
//    // jpeg的结构体，宽保存的比如、高、位深、图片格式等信息
//    struct jpeg_compress_struct jcs;
//
//    struct my_error_mgr jem;
//
//    jcs.err = jpeg_std_error(&jem.pub);
//    jem.pub.error_exit = my_error_exit;
//    if (setjmp(jem.setjmp_buffer)) {
//        return 0;
//    }
//    jpeg_create_compress(&jcs);
//    // 打开输出文件 wb:可写byte
//    FILE *f = fopen(outfilename, "wb");
//    if (f == NULL) {
//        return 0;
//    }
//    // 设置结构体的文件路径
//    jpeg_stdio_dest(&jcs, f);
//    jcs.image_width = w;
//    jcs.image_height = h;
//
//    // 设置哈夫曼编码
//    jcs.arith_code = false;
//    jcs.input_components = nComponent;
//    if (nComponent == 1)
//        jcs.in_color_space = JCS_GRAYSCALE;
//    else
//        jcs.in_color_space = JCS_RGB;
//
//    jpeg_set_defaults(&jcs);
//    jcs.optimize_coding = optimize;
//    jpeg_set_quality(&jcs, quality, true);
//    // 开始压缩，写入全部像素
//    jpeg_start_compress(&jcs, TRUE);
//
//    JSAMPROW row_pointer[1];
//    int row_stride;
//    row_stride = jcs.image_width * nComponent;
//    while (jcs.next_scanline < jcs.image_height) {
//        row_pointer[0] = &data[jcs.next_scanline * row_stride];
//        jpeg_write_scanlines(&jcs, row_pointer, 1);
//    }
//
//    jpeg_finish_compress(&jcs);
//    jpeg_destroy_compress(&jcs);
//    fclose(f);
//
//    return 1;
//}
//
//typedef struct {
//    uint8_t r;
//    uint8_t g;
//    uint8_t b;
//} rgb;
//
//char *jstrinTostring(JNIEnv *env, jbyteArray barr) {
//    char *rtn = NULL;
//    jsize alen = env->GetArrayLength(barr);
//    jbyte *ba = env->GetByteArrayElements(barr, 0);
//    if (alen > 0) {
//        rtn = (char *) malloc(alen + 1);
//        memcpy(rtn, ba, alen);
//        rtn[alen] = 0;
//    }
//    env->ReleaseByteArrayElements(barr, ba, 0);
//    return rtn;
//}
//
//JNIEXPORT jstring JNICALL
//Java_com_caesar_auto_utils_EffectiveBitmapUtils_compressBitmap(JNIEnv *env,
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
//        return env->NewStringUTF( "0");;
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
//
//        }
//
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