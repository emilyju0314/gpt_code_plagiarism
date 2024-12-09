#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	LL a[n];
	LL ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i > 0 && a[i] == a[i-1]){
			ans++;
			a[i] = -1000;
		}
	}
	cout << ans << endl;
}
