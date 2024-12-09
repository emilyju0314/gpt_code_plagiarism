#include <bits//stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i*m+j*n-i*j*2==k){
				cout<<"Yes\n"<<endl;
				return 0;
			}
		}
	}
	cout<<"No\n";
}
