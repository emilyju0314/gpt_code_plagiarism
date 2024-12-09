#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,n;
int main(){
	cin>>a>>b>>n;
	LL f=min(b-1,n);
	LL ans=a*f/b;
	cout<<ans;
}