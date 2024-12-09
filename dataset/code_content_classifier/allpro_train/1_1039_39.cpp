#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<double> > hei(n);
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		hei[i].push_back(0);
		for(int j=0; j<k; j++){
			int s,h;
			cin >> s >> h;
			for(int d=0; d<s*h; d++){
				hei[i].push_back(hei[i].back()+(double)1/s);
			}
		}
	}

	vector<double> dp(m+1, 0);
	for(int i=0; i<n; i++){
		auto ndp = dp;
		for(int j=1; j<(int)hei[i].size(); j++){
			for(int k=m; k>=0; k--){
				if(k+j > m) continue;
				ndp[k+j] = max(ndp[k+j], dp[k]+hei[i][j]); 
			}
		}
		dp = ndp;
	}
	cout << fixed << setprecision(10);
	cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
