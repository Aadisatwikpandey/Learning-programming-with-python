#include<stdio.h>

int main(){
    int a = 8;
    int* p = &a;
    int** q = &p;
    printf("%d\n",a);
    // printf("%d\n",p);
    // printf("%d\n",q);
    printf("%d\n",*p);
    printf("%d\n",**q);
    // printf("%d\n",*q);
    int k = *p;
    int j = **q;
    printf("%d\n",k);
    printf("%d\n",j);

}