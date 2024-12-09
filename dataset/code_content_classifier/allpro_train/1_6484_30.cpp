#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> c(n);
	for(int i = 0; i < m; ++i){
		int a, l;
		cin >> a >> l;
		for(int j = 0; j < l; ++j){ c[(a + j) % n] = 1; }
	}
	int offset = 0;
	while(offset < n && c[offset] != 0){ ++offset; }
	map<int, int> mp;
	int cur_len = 0;
	for(int i = 0; i < n; ++i){
		if(c[(i + offset) % n] == 0){
			if(cur_len > 0){ mp[cur_len]++; }
			cur_len = 0;
		}else{
			++cur_len;
		}
	}
	if(cur_len > 0){ mp[cur_len]++; }
	for(auto it = mp.rbegin(); it != mp.rend(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
