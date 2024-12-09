#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,h[200001],tot;
	cin >> a >> b;
	for(int i = 0;i < a;i++){
		cin >> h[i];
	}
	sort(h,h+a);
	for(int i = 0;i < a-b;i++){
		tot+=h[i];
	}
	cout << tot << '\n';
}