#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;
	int a=1,b=n;
	rep(i,m){
		int l,r; cin>>l>>r;
		a=max(a,l);
		b=min(b,r);
	}
	cout<<max(b-a+1,0)<<endl;

	return 0;
}
