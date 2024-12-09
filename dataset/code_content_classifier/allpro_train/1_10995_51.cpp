#define ll long long
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
int arr[N];
vector<int> v1, v2;
int n, x;
void solve(){
	cin >> n;
	unordered_map<int,int> l, r;
	vector<int> rs;
	v1.clear();
	for(int i = 0; i < n; i++) cin >> x, v1.pb(x);
	for(int i = 1; i <= n; i++){
		int val1 = v1[i - 1];
		int val2 = v1[n - i];
		l[val1]++;
		l[val2]--;
		if(l[val2] == 0) l.erase(val2);
		if(l[val1] == 0) l.erase(val1);
		if(l.size() == 0) rs.pb(i);
	}
	for(int i = 0; i < rs.size(); i++){
		if(i) cout << " ";
		cout << rs[i];
	}
	cout << endl;
}
int main(){
	solve();
	return 0;
}
