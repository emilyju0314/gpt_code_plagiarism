#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;

int main() {
	int n;
	while(cin >> n, n) {
		int ans = 0;
		int lim = sqrt(n);
		for(int i=0; i<=lim; i++) {
			for(int j=i; j<=lim && i*i+j*j<=n; j++) {
				for(int k=j; k<=lim && i*i+j*j+k*k<=n; k++) {
					int sq = n - i*i - j*j - k*k;
					if( k*k<=sq && ((int)sqrt(sq))*((int)sqrt(sq)) == sq ) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}