#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn];
int main(){
	int n;
	int mx=-2000000000,mn=0x3f3f3f3f;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	mn=a[1];
	for(int i=2;i<=n;i++){
		mx=max(mx,a[i]-mn);
		mn=min(mn,a[i]);
	}
	cout<<mx<<endl;
	return 0;
}
