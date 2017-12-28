#include <jni.h>
#include <string>
#include <android/log.h>
#include "../jni/MyLog.h"

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
