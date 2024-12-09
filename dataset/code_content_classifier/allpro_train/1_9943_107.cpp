#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int s = 0, x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += 2*min(x, abs(k-x));
	}
	cout << s << endl;
}
