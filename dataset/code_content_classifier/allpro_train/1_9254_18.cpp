#define _AOJ_
#include "bits/stdc++.h"
using namespace std;
typedef long long i64;
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,a,b) for(int i=a;i<b;++i)
#define all(c) c.begin(),c.end()

//define pfs,bellmanford,etc.

int main(){
	i64 n,k;cin>>n>>k;
	i64 s=1,ans=1;
	vector<i64>a(1,1);
	while(s<=n){
		a.push_back((s+k-1)/k);
		s+=a.back();
		if(s<=n)ans=a.size();
	}
	cout<<ans<<endl;
}

//sub-EOF
