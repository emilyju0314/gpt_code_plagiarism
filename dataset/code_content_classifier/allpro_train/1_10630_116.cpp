#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+2;
int a[N],b[N];
pair<int,int> c[N];
signed main(){
	int n,i,j,sum1=0,sum2=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i].first=a[i]+b[i];
		c[i].second=i;
	}
	sort(c+1,c+1+n);
	for(i=n,j=0;i>=1;j++,i--){
		if(j%2==0){
			sum1+=a[c[i].second];
		}
		else{
			sum2+=b[c[i].second];
		}
	}
	cout<<sum1-sum2;
}