//
// Created by heshengfang on 2018/9/15.
//
#include <jni.h>
#include <string>
#include "codenza.h"
#include "logs.h"


extern "C"
JNIEXPORT jstring JNICALL
Java_com_caesar_auto_natives_NativeTest_testCodenza(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello testCodenza";
    LOGV("hello testCodenza");
    codenza();
    return env->NewStringUTF(hello.c_str());
}