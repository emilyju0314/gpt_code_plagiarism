#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
int n,d,fail[N];
ll l,r,s[N][30];
char a[N];
void KMP(){
	int k=0;
	for (int i=2;i<=n;i++){
		for (;k&&a[k+1]!=a[i];) k=fail[k];
		fail[i]=(k+=(a[k+1]==a[i]));
	}
	d=n-fail[n];
}
ll fib(ll p,int c){
	if (p<=n) return s[p][c];
	if (p<=n*2) return s[n][c]+s[p-n][c];
	ll ans1=s[n][c]+s[d][c],ans2=s[n][c];
	ll a=n+d,b=n;
	for (;p>a+b;){
		ll c=ans1; ans1+=ans2; ans2=c;
		c=a; a+=b; b=c;
	}
	return ans1+fib(p-a,c);
}
ll calc(ll p,int c){
	if (p<=n) return s[p][c];
	if(n%d==0){
		ll ans=(p-n)/d*s[d][c]+s[n][c];
		return ans+s[(p-n)%d][c];
	}
	return fib(p,c);
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1)/2;
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++)
			s[i][j]=s[i-1][j];
		s[i][a[i]-'a']++;
	}
	KMP();
	scanf("%lld%lld",&l,&r);
	for (int i=0;i<26;i++)
		printf("%lld ",calc(r,i)-calc(l-1,i));
}