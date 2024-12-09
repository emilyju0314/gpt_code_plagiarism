#include <stdio.h>
int main (){
long long int x,a,b;
scanf("%lld %lld %lld",&x,&a,&b);
if ((b-a)<=0){
printf("delicious");
}else if((b-a)<=x){
printf("safe");
}else{
printf("dangerous");
}
return 0;
}