#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef enum
{
    OK = 0,
    ERROR_FILE_OPEN,  // 文件打开失败
    ERROR_FILE_READ,  // 文件读取失败
    ERROR_FILE_WRITE, // 文件写入失败

}Status;

#endif