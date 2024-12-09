#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

int n,m,k;
int x,y;
map<int,int> mp1,mp2;
map<pair<int,int>,int> mp;
vector<int> v1,v2;

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin>>n>>m>>k;
	forn(i,0,k){
		cin>>x>>y;
		x--,y--;
		mp1[x]++;
		mp2[y]++;
		mp[make_pair(x,y)]++;
	}
	int mx1=0,mx2=0;
	forn(i,0,n)
		mx1=max(mx1,mp1[i]);
	forn(i,0,m)
		mx2=max(mx2,mp2[i]);
	forn(i,0,n)
		if (mp1[i]==mx1)
			v1.push_back(i);
	forn(i,0,m)
		if (mp2[i]==mx2)
			v2.push_back(i);
	forn(i,0,v1.size())
		forn(j,0,v2.size())
			if (mp[make_pair(v1[i],v2[j])]==0){
				cout<<mx1+mx2<<endl;
				return 0;
			}
	cout<<mx1+mx2-1<<endl;
	return 0;
}