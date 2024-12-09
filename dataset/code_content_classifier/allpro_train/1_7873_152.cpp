#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,d;
	while(cin >> n >> d && n){
		vector<int> ms[n];
		int tot[100] = {};
		int l = 0;
		for(int i = 0 ; i < n ; i++){
			int k;
			cin >> k;
			l += k;
			while(k--){
				int t;
				cin >> t;
				ms[i].push_back(t);
				tot[i] += t;
			}

		}
		for(int i = 0 ; i < l ; i++){
			pair<int,int> idx = {1e9,-1};
			for(int j = 0 ; j < n ; j++){
				if( ms[j].size() ){
					int s = ms[j].back();
					int mi=1e9,mx=-1e9;
					for(int k = 0 ; k < n ; k++){
						int v = k == j ? tot[j] - s : tot[k];
						mi = min(mi,v);
						mx = max(mx,v);
					}
					idx = min(idx,make_pair(mx-mi,j));
				}
			}
			//cout << idx.first << " " << idx.second << endl;
			if( idx.first > d ){
				cout << "No" << endl;

				goto ex;
			}
			tot[idx.second] -= ms[idx.second].back();
			ms[idx.second].pop_back();
		}
		cout << "Yes" << endl;
		ex:;
	}
}