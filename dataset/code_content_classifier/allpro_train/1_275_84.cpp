#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll              long long int
#define mod             1000000007 
#define fo(i,l,r)       for(i=l;i<=r;i++)
#define decimal(i)      setprecision(i)

ll calc(int r1, int c1, int r2, int c2){
	ll cost = 0;
	if(r1==r2 && c1==c2){
		return 0;
	}
	if((r2-c2)%2){
		return (r2-c2-r1+c1)/2;
	}
	else{
		if(r2-c2>r1-c1){
			return 1+(r2-c2-r1+c1-1)/2;
		}
		else{
			return r2-r1;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,tt;
	cin >> T;
	fo(tt, 0, T-1){
		int n;
		cin >> n;
		int r[n],c[n];
		for(int i=0;i<n;i++){
			cin >> r[i];
		}
		vector<pair<int, int> > p;
		for(int i=0;i<n;i++){
			cin >> c[i];
			p.push_back(make_pair(r[i], c[i]));
		}
		sort(p.begin(), p.end());
		ll cost = calc(1, 1, p[0].first, p[0].second);
		for(int i=1;i<n;i++){
			cost += calc(p[i-1].first, p[i-1].second, p[i].first, p[i].second);
		}
		cout << cost << endl;
	}
	return 0;
}
