//
// Created by heshengfang on 2018/9/1.
//

#include <iostream>
#include "logs.h"

#ifndef T_AUTO_CYCLE_H
#define T_AUTO_CYCLE_H

#endif //T_AUTO_CYCLE_H


using namespace std;

void cycle_while() {
    //局部变量声明
    int a = 10;
    //while循环执行
    while (a < 20) {
        LOGD("while i = %d", a);
        a++;
    }
}

void cycle_for() {
    //for循环执行
    for (int i = 10; i < 20; ++i) {
        LOGV("for i = %d", i);
    }
}

void cycle_do_while() {
    //局部变量
    int a = 10;
    //do循环执行
    do {
        LOGE("do_while a = %d", a);
        a = a + 1;
    } while (a < 20);

}

void cycle_nesting() {
    int i, j;
    for (i = 2; i < 100; i++) {
        for (j = 2; j <= (i / j); j++) {
            if (!(i / j)) {
                LOGI("break i = %d", i);
                LOGI("break j = %d", j);
                break;
            }
            if (j > (i / j)) {
                LOGW("ok i = %d", i);
            }
        }
    }
}

void cycle_break() {
    int a = 10;
    do {
        a = a + 1;
        if (a > 15) {
            LOGE("end = %d", a);
            break;
        }
    } while (a < 20);
}

void cycle_continue() {
    int a = 10;
    do {
        if (a == 15) {
            //跳过迭代
            a = a + 1;
            continue;
        }
        LOGE("continue a = %d", a);
        a = a + 1;
    } while (a < 20);
}


void cycle_goto() {
    int a = 10;
    LOOP:
    do {
        if (a == 15) {
            //跳过迭代
            a = a + 1;
            goto LOOP;
        }
        LOGI("goto = %d", a);
        a = a + 1;
    } while (a < 20);
}





