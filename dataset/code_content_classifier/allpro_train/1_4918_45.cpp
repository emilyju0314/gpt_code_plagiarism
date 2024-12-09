#include <stdio.h>

void swap(int *a, int *b){
int c=*a;
*a=*b;
*b=c;
return;
}

int main(void)
{
int w,n;
scanf("%d",&w);
int list[w-1];
for(int i=0;i<w;i++)
list[i]=i+1;
scanf("%d",&n);
for(int i=0;i<n;i++){
int a,b;
scanf("%d,%d",&a,&b);
swap(&list[a-1],&list[b-1]);
}
for(int i=0;i<w;i++){
printf("%d\n",list[i]);
}
return 0;
}