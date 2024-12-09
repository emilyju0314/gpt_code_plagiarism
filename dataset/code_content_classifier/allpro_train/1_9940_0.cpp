#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans;
signed main(){
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]&&b[i]==c[i]){}
		else if(a[i]==b[i]||b[i]==c[i]||a[i]==c[i]){
			ans++;
		}
		else{
			ans+=2;
		}
	}
	cout<<ans<<endl;
}