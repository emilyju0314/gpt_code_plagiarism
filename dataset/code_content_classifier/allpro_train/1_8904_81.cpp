#include <bits/stdc++.h>
using namespace std;

int n;
long double t, x, h, ans;

int main(){
	cin >> n >> t;
	for(int i=0;i<n;i++){
		cin >> x >> h;
		if(ans<t*h/x) ans = t*h/x;
	}
	printf("%.4Lf\n", ans);
	return 0;
}
