#include "transfer.h"

Status transfer_file(char *source_file, char *target_file)
{
    int sfd = open(source_file, O_RDONLY);
    if(sfd == -1)
    {
        return ERROR_FILE_OPEN;
    }

    int tfd = open(target_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(tfd == -1)
    {
        close(sfd);
        return ERROR_FILE_OPEN;
    }

    char buf[1024];
    ssize_t rret;
    ssize_t wret;
    ssize_t written = 0;
    while(1)
    {
        rret = read(sfd, buf, 1024);
        if(rret == -1)
        {
            close(sfd);
            close(tfd);
            return ERROR_FILE_READ;
        }
            
        if(rret == 0)
            break;

        wret = write(tfd, buf, rret);
        if(wret < rret && wret > 0)
        {
            written = wret;
            while(written < rret)
            {
                wret = write(tfd, buf+written, rret-written);
                if(wret == -1)
                {
                    close(sfd);
                    close(tfd);
                    return ERROR_FILE_WRITE;
                }

                written = written + wret;
            }
        }
        if(wret == -1)
        {
            close(sfd);
            close(tfd);
            return ERROR_FILE_WRITE;
        }
        
    }
    
    close(sfd);
    close(tfd);
    return OK;
}