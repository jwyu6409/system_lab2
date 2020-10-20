/* dltest.c */
#include <stdio.h>
#include <dlfcn.h>
#include "testlib.h"

int main(){
	void *handle;
	int (*Add)(int,int);
	int (*Sub)(int,int);
	int (*Mul)(int,int);
	int (*Div)(int,int);

	char *error;
	int a, b;
	handle = dlopen("./libtest.so",RTLD_LAZY);

	if(!handle){
		fputs(dlerror(),stderr);
	}

	Add=dlsym(handle,"Add");
	Sub=dlsym(handle,"Sub");
	Mul=dlsym(handle,"Mul");
	Div=dlsym(handle,"Div");
	printf("정수를 입력하세요 : ");
	scanf("%d %d",&a,&b);
	printf("%d + %d = %d\n",a,b,(*Add)(a,b));
	printf("%d - %d = %d\n",a,b,(*Sub)(a,b));
	printf("%d * %d = %d\n",a,b,(*Mul)(a,b));
	printf("%d / %d = %d\n",a,b,(*Div)(a,b));
	dlclose(handle);
}
