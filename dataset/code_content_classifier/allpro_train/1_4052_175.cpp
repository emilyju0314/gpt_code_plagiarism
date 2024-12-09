#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> a(1e5,0);
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a[b]++;
	}
	
	int ans=0;
	
	for(int i=0;i<1e5-2;i++){
		int sum=a[i]+a[i+1]+a[i+2];
		ans=max(ans,sum);
	}
	
	cout<<ans<<endl;
	return 0;
}