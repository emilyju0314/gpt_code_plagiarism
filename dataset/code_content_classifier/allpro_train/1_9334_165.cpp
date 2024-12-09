#include <bits/stdc++.h>
using namespace std;
int v[200200];
int ctr;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	ctr = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		v[i] = t;
	}
	int s = 1,e=n;
	int ls = n;
	while(s <= e) {
		map<int,int> mp;
		int m = (s+e)/2;
		bool po = true;
		for(int i=0;i<n-1;i++) {
			if(v[i+1] <= v[i]) {
				for(auto it = mp.rbegin();it != mp.rend() && it->first > v[i+1];) {
					mp.erase(it->first);
					it = mp.rbegin();
				}
				mp[v[i+1]]++;
				int id = v[i+1];
				while(id > 0 && mp[id] >= m) {
					if(m == 1) {po = false;break;}
					mp[id] -= m;
					mp[--id]++;
				}
				if(mp[0] > 0) {po = false;break;}
			}
			if(!po) break;
		}
		if(po) {
			ls = m;e = m-1;
		} else {
			s = m+1;
		}
	}
	printf("%d\n",ls);
}
