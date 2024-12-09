#include <bits/stdc++.h>
using namespace std;
long double recur(long double a, long double b, long double c, long double d)
{
//	cout << fixed << setprecision(6) << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	if (abs(a)>0.000001)
	{
		if (abs(b)>0.000001)
		{
			long double x=min(a, d), y=min(b, d);
			long double ans=a*(recur(a-x, b+x/2.0, c+x/2.0, d)+1)+b*(recur(a+y/2.0, b-y, c+y/2.0, d)+1)+c;
//			cout << ans << '\n';
			return ans;
		}
		else
		{
			long double x=min(a, d);
			long double ans=a*(recur(a-x, 0.0, c+x, d)+1)+c;
//			cout << ans << '\n';
			return ans;
		}
	}
	else
	{
		if (abs(b)>0.000001)
		{
			long double y=min(b, d);
			long double ans=b*(recur(0.0, b-y, c+y, d)+1)+c;
//			cout << "special: " << b << ' ' << recur(0.0, b-y, c+y, d) << ' ' << ans << '\n';
			return ans;
		}
		else
		{
//			cout << 1.0 << '\n';
			return 1.0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		long double a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << fixed << setprecision(7) << recur(a, b, c, d) << '\n';
	}
	return 0;
}