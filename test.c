#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    
    int *x ;
    int *y = x;
    int b = 6;
    x = &b;
    printf("%d %d %d",x,&x,y);
    return 0;
}
