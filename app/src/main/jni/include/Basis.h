//
// Created by heshengfang on 2018/9/15.
//
#include <iostream>
#include "logs.h"
#include "android_buf.h"

#ifndef T_AUTO_BASIS_H
#define T_AUTO_BASIS_H

#endif //T_AUTO_BASIS_H

using namespace std;

void basis() {
    int a = 10;
    while (a < 20) {
        LOGD("while a = %d", a);
        a++;
    }

//    unsigned char data[8] = {0x0C,0x0A,0x13,0x09,0x0C,0x0B,0x06,0x08};

//    memset(data, 0x0C, sizeof(data));    // right
//    memset(data, 0x0A, sizeof(data));    // right
//    memset(data, 0x13, sizeof(data));    // right
//    memset(data, 0x09, sizeof(data));    // right
//    memset(data, 0x0C, sizeof(data));    // right
//    memset(data, 0x0B, sizeof(data));    // right
//    memset(data, 0x06, sizeof(data));    // right
//    memset(data, 0x08, sizeof(data));    // right
//    char s = *(char *)(data + 6 * 4);
//    LOGD("arrays i = %x", data[3]);
//    *(long *)(data + i * 4) = s和s = *(long *)(data + i * 4)
}

void arrays() {
    int a[5][2] = {{0, 0},
                   {1, 2},
                   {2, 4},
                   {3, 6},
                   {4, 8}};
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            LOGD("arrays i = %d", i);
//            LOGD("arrays j = %d", j);
//        }
//    }
}