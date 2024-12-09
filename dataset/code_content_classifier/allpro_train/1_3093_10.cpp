#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	int n; cin >> n; int a[n], b[n], ds = 0;
	for(int i=0; i<n; i++) cin >>a[i];
	for(int i=0; i<n; i++) {
		cin >> b[i]; ds += a[i] == b[i];
	}
	ll an = 0; bool update = true;
  while (ds != n && update) {
		update = false;
		for(int j=0; j<n; j++){
			int p = b[(j+n-1)%n] + b[(j+1)%n];
			//cout << j << " " << p << " " << b[j] << " " << b[j] - p << " " << update<< endl;
			if (b[j] - p >= a[j]) {
				int c = (b[j] - a[j]) / p;
				b[j] -= p * c; an+=c;
				if (a[j] == b[j]) ds++;
				update = true;
			}
		}
	}
	if (ds != n) cout << "-1" << endl;
	else cout << an << endl;
}