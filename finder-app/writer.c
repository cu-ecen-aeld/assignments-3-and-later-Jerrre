#include <stdio.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char* argv[]){
    
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3){
        syslog(LOG_ERR, "ERROR: The number of arguments should be 2. The first argument should be the full path to a file. The second argument should be a string to be written in that file.\n");
        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];

    FILE *fd;
    fd = fopen(writefile, "w");
    if(!fd){
        syslog(LOG_ERR, "ERROR: Failed to open file: %s\n", writefile);
        return 1;
    }

    fwrite(writestr, sizeof(char), strlen(writestr), fd);
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);

    fclose(fd);
    closelog();

    return 0;
}