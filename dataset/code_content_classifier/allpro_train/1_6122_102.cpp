#include<bits/stdc++.h>
#pragma O3
using namespace std;
map<pair<int,int>,int> mp;
vector<pair<int,int> > r;
signed main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,x,y,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		r.push_back({x,y});
	}
	sort(r.begin(),r.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			x=r[j].first-r[i].first;
			y=r[j].second-r[i].second;
			mp[{x,y}]++;
			ans=max(ans,mp[{x,y}]);
		}
	}
	cout<<n-ans;
}
