#include<stdio.h>
int main(){
long n,m,i,j,pi,pj,a,b,c,ans;
char s[111111],t[111111];
scanf("%ld%ld",&n,&m);
scanf("%s%s",s,t);
a=n;
b=m;
c=n%m;
while(c!=0){
a=b;
b=c;
c=a%b;
}
pi=n/b;
pj=m/b;
i=0;
j=0;
while(i<n){
if(s[i]!=t[j]){
printf("-1\n");
return 0;
}
i+=pi;
j+=pj;
}
ans=n*m/b;
printf("%ld\n",ans);
return 0;
}
