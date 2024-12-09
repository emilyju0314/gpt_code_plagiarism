#include<cstdio>
#define re register
using namespace std;
int n,a,b,c,d;
signed main(){
b=1;
scanf("%d",&n);
while(n--){
	scanf("%d",&a);
	if(a!=b)++c;
	else ++b;
}
if(b>1)
printf("%d",c);
else puts("-1");
}
