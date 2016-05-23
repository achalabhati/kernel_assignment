#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/sched.h>
#include <linux/fs.h> 
#include<stdlib.h>
#define STACKSIZE 1024*1024

long create(void (*fn)(void),void *child_stack,int flags)
{
long rtn;
rtn = syscall(325,fn,child_stack,flags);
return rtn;
}

void ch_fun()
{
printf("\nSUSSSSSSSSS i am child \n");
}
int main()
{
    int p = getpid();
    long rtn;
void *data;
void ** newstack;
newstack = (void **) malloc(STACKSIZE);
newstack = (void **) (STACKSIZE + (char *) newstack);
*newstack = &ch_fun;
    if(!newstack) {
        printf("The stack failed\n");
}

printf("\nachala\n");
rtn = create(&ch_fun,newstack,CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FS|CLONE_THREAD);
if(rtn)
{
    printf("\n achala sus created\n %ld",rtn);
}

printf("\nachala\n");
printf("\n achala sus created\n %ld",rtn);
    return 0;
}

