#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int fd;

    openlog(argv[0], LOG_PID, LOG_USER);

    if(argc < 3)
    {
        printf("missing arguments\r\n");
        return 1;
    }

    fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(fd == -1)
    {
        syslog(LOG_ERR, "can't open %s: %m", argv[1]);
        closelog();
        printf("can't open %s\r\n", argv[1]);
        return 1;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    closelog();
    write(fd, argv[2], strlen(argv[2]));
    close(fd);

    return 0;
}