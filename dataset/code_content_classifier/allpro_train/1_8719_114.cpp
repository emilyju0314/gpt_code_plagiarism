#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

#define M 1000000007

int main(){
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	rep(i, n) cin>>a[i];

	if(n==k){
		ll ans=1;
		rep(i, k) ans=(ans*((a[i]+M)%M))%M;
		cout << ans << endl;
		return 0;
	}

	int nump=0, numm=0, num0=0;
	vector<int> ap, am;
	rep(i, n){
		if(a[i]>=0) ap.push_back(a[i]);
		if(a[i]<0) am.push_back(a[i]);
	}

	if(am.size()==n && k%2==1){
		sort(am.rbegin(), am.rend());
		ll ans=1;
		rep(i, k) ans=(ans*((am[i]+M)%M))%M;
		cout << ans << endl;
		return 0;
	}

	sort(ap.rbegin(), ap.rend());
	sort(am.begin(), am.end());

	int nm=min((k/2)*2, (int)(am.size()/2)*2);
	int np=k-nm;
	while(np+2<=ap.size() && nm-2>=0 && (ll)ap[np]*ap[np+1] > (ll)am[nm-1]*am[nm-2]){
		np+=2;
		nm-=2;
	}

	ll ans=1;
	rep(i, np) ans=(ans*ap[i])%M;
	rep(i, nm) ans=(ans*((am[i]+M)%M))%M;

	cout << ans << endl;
	return 0;
}

