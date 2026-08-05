#include "common.h"
#include "transfer.h"

int main(int argc, char *argv[]) //命令行参数怎么搞
{
    if(argc != 3)
    {
        printf("参数出错！！！\n");
        return 0;
    }

    transfer_file(argv[1], argv[2]);
}