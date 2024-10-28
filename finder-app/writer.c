#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    openlog(NULL, 0, LOG_USER);
    if (argc < 3) {
        syslog(LOG_ERR, "Not sufficient arguments. Want 2, got %d", argc - 1);
        return 1;
    }
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    int fd;
    fd = open(writefile, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    if (fd == -1) {
        perror("open");
        syslog(LOG_ERR, "Opening file %s failed", writefile);
    }

    ssize_t ret, nr;
    size_t len = strlen(writestr);
    while (len != 0 && (ret = write(fd, writestr, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR) continue;
            perror("write");
            syslog(LOG_ERR, "Writing file %s failed", writefile);
            break;
        }
        len -= ret;
        writestr += ret;
    }

    if (!len) {
        syslog(LOG_DEBUG, "Writing %s to file %s", writestr, writefile);
    }

    if (close(fd) == -1) {
        perror("close");
        syslog(LOG_ERR, "Closing file %s failed", writefile);
    }

    return 0;
}
