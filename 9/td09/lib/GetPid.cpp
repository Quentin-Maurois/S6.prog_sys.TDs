#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "GetPid.h"

JNIEXPORT jlong JNICALL
Java_GetPid_getPid(JNIEnv *, jclass) {
    return getpid();
} 