#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>f(1000005);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
		mx = max(mx, a[i]);
	}
	int ans = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (f[x] == 1)ans++;
		for (int j = 2; x * j <= mx; j++)
			f[x * j] = 0;
	}
	cout << ans;
		
	
	
}