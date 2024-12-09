#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	long long ans=0;
	for(int i=0;i<n;++i) {
		int v; cin >> v;
		ans+=v-i-1;
	}
	cout << ans << endl;
	
	return 0;
}

