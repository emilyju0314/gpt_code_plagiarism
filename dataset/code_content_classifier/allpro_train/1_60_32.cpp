#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100010];
int main(){
	cin>>n>>m;
	a[0]=1;
	for(long long i=0;i<m;i++){
		int x;
		cin>>x;
		a[x]=-1;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]!=-1){
			if(a[i-1]!=-1)
				a[i]+=a[i-1]%1000000007;
			if(a[i-2]!=-1)
				a[i]+=a[i-2]%1000000007;
		}
	}
	cout<<a[n]%1000000007;
	return 0;
}