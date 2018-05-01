#include <jni.h>
#include <string>
#include <android/log.h>
#include "MyLog.h"

extern "C"
JNIEXPORT jstring JNICALL Java_com_caesar_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGV("hello verbose");
    LOGD("hello debug");
    LOGI("hello info");
    LOGW("hello warn");
    LOGE("hello error");
    return env->NewStringUTF(hello.c_str());
}


///*
// * Class:     com_caesar_ndkdemo_MainActivity
// * Method:    intFromJNI
// * Signature: ()I
// */
//JNIEXPORT jint JNICALL Java_com_caesar_ndkdemo_MainActivity_intFromJNI
//        (JNIEnv *, jobject){
//    LOGD("intFromJNI");
//    LOGE("intFromJNI");
//    LOGI("intFromJNI");
//    int i = 880;
//
//    return i;
//}
//
///*
// * Class:     com_caesar_ndkdemo_MainActivity
// * Method:    LongFromJNI
// * Signature: ()J
// */
//JNIEXPORT jlong JNICALL Java_com_caesar_ndkdemo_MainActivity_LongFromJNI
//        (JNIEnv *, jobject){
//    LOGD("LongFromJNI");
//    LOGE("LongFromJNI");
//    LOGI("LongFromJNI");
//    unsigned long long deviceId = 123242l;
//    return deviceId;
//}
//
///*
// * Class:     com_caesar_ndkdemo_MainActivity
// * Method:    aCharFromJNI
// * Signature: ()C
// */
//JNIEXPORT jchar JNICALL Java_com_caesar_ndkdemo_MainActivity_aCharFromJNI
//        (JNIEnv *, jobject){
//    LOGD("aCharFromJNI");
//    LOGE("aCharFromJNI");
//    LOGI("aCharFromJNI");
//    int64_t level = 88;
//    unsigned char l = (level & 0xFF);
//    return l;
//}
