#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	string s[300];
	cin >> n;
	for(int i = 0; i < n; i++)cin >> s[i];
	int ans = 0;
	for(int mx = 0; mx < n; mx++)
	{
		bool ok = true;
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < n; y++)
			{
				if(s[(x + mx) % n][y] != s[(y + mx) % n][x])ok = false;
			}
		}
		if(ok)ans++;
	}
	cout << ans * n << endl;

	return 0;
}
