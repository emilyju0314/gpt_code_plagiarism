#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a,b,c,ans=0;
void work(){
	if(ans>1000) return ;
	if(a%2 or b%2 or c%2) {
		cout<<ans;exit(0);
	}
	int aa,bb,cc;
	aa=b/2+c/2,bb=a/2+c/2,cc=a/2+b/2;
	a=aa,b=bb,c=cc;
	ans++;work();
}
signed main(){
	cin>>a>>b>>c;
	work();
	puts("-1");
	
	return 0;
}