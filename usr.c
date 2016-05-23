#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  <signal.h>

void main()
{
int k;
k=create();
if(k)
{
printf("system call");
}
}
