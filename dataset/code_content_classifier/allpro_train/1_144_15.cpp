#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
int a[105],b[105],c[105];

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<n;i++) cin >> c[i];
	for(int i=1;i<=n;i++)
	{
		ans+=b[a[i]];
		if(a[i]==a[i-1]+1) ans+=c[a[i-1]];
	}
	cout << ans << endl;
	return 0;
}
