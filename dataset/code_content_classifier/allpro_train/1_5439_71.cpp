#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<int> p(n);
	int ra[n+1];
	for(int i=0;i<n;i++){
		cin >> p[i];
		ra[p[i]]=i;
	}
	ll ans=0;
	set<int> S;
	S.insert(-1); S.insert(n);
	for(ll d=1;d<=n;d++){
		int i=ra[d];
		auto it=S.lower_bound(i);
		int r=*it;
		it--;
		int l=*it;
		ans+=d*(i-l)*(r-i);
		S.insert(i);
	}
	cout << ans << endl;
}