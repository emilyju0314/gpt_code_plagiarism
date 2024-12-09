#include<iostream>
using namespace std;

int main(){
while(1){
	char s[1000000+2];
	int n,m,ans=0,c=0;
	scanf("%d",&n);
if(n==0)break;
	scanf("%d",&m);
	scanf("%s",&s);
	for(int i=0;i<m;i++){
		if((c%2==0&&s[i]=='I')||(c%2==1&&s[i]=='O'))c++;
		else{
			if(c>=2*n+1)ans+=1-n+((c-1)-(c-1)%2)/2;
			c=0;
			if(s[i]=='I')c=1;
		}
	}
	printf("%d\n",ans);
}
}