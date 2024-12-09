#include "bits/stdc++.h"
using namespace std;
int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a%b);
}
int main(){
	int n,X,x,ans;cin>>n>>X;
	cin>>x;ans=abs(x-X);
	for (int i=1;i<n;++i){
		cin>>x;ans=gcd(abs(x-X),ans);
	}cout<<ans;
}