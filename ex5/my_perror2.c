#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

main(const char *s){
	if(s!=NULL)
		printf("%s: ", s);
	else
		printf("%s\n", strerror(errno));
	exit(1);
}
