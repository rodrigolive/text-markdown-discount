#include <stdio.h>
#include <string.h>

#include "config.h"

int
main(argc, argv)
int argc;
char **argv;
{
    FILE * pipe;

    char line[1024];

    freopen("/dev/null", "w", stderr);
    pipe = popen("git branch | awk '$1 ~ /\\*/ { print $2; }'", "r");
    if ( pipe == NULL )
	return 0;

    if ( fgets(line, sizeof line, pipe) != 0 ) {
	strtok(line, "\n");
	if ( strcmp(line, "master" ) != 0 )
	    printf("\"(%s)\"", line);
    }
    pclose(pipe);
    return 0;
}
