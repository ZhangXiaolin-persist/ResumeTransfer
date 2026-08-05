#ifndef TRANSFER_H
#define TRANSFER_H

#include "common.h"

// 文件内容转移函数  
// 参数：源文件名 目标文件名（无文件则创建）
// 返回值：ERROR_FILE_OPEN（文件打开失败） ERROR_FILE_WRITE(文件写入失败) 
//        ERROR_FILE_READ （文件读取失败）
Status transfer_file(char *source_file, char *target_file);

#endif