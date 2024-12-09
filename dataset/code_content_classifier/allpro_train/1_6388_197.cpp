#include <iostream>
using namespace std;
int n;
long long a[55];
inline int mx(){
	int res=0;
	for(int i=1;i<n;i++){
		if(a[i]>a[res])res=i;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
        cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=0;
	long long ans=0;
	while(a[t=mx()]>=n){
		ans+=a[t]/n;
		for(int i=0;i<n;i++){
			if(i==t)continue;
			a[i]+=a[t]/n;
		}
		a[t]%=n;
	}
	cout<<ans<<endl;
	return 0;
}