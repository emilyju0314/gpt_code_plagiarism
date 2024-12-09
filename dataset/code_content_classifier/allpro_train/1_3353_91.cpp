#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

vector<int> x[100100];
	
int main(){
	int n, m; cin >> n >> m;
	for( int i = 0; i < n; ++i ){
		int a, b; cin >> a >> b;
		x[a].push_back(b);
	}
	priority_queue<int> pq;
	ll ans = 0;
	for( int i = 1; i <= m; ++i ){
		for( auto k : x[i] ) pq.push(k);
		if( !pq.empty() ){
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
}
