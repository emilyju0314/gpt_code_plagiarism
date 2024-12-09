//Bishmillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pll pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define pb push_back
#define ff first
#define ss second
#define pi acos(-1.0)
#define tan(a) atan(a)/(pi/180)
#define sin(a) asin(a)/(pi/180)
#define cos(a) cos(a)/(pi/180)
#define test ll tc;cin>>tc; while(tc--){solve();}
#define max   99999999
#define inf   1<<30
#define eps   1e-9
#define mod   1000000007
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define case(tc) cout << "Case " << tc <<": "
#define all(qz) qz.begin(),qz.end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

void iofun() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll Pow(ll c, ll d) {return d == 0 ? 1 : c * pow(c, d - 1);}
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return ((a * b) / gcd(a, b));}
bool isEven(ll& n) { return (n & 1) == 0; }

void solve()
{
	ll a, b;
	string s;
	cin >> a >> b >> s;
	bool ans = true;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '0') a--;
		else if (s[i] == '1') b--;
	}
	if ( a < 0 || b < 0)
	{
		cout << "-1\n";
		return;
	}
	if (a == 0 && b == 0)
	{
		string t = s;
		reverse(s.begin(), s.end());
		if (s == t)
		{
			cout << s << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		return;
	}
	for (int i = 0, j = s.size() - 1; i < j; ++i, j--)
	{
		if ((s[i] == '0' && s[j] == '?') || (s[i] == '?' && s[j] == '0'))
		{
			if (a < 1)
			{
				ans = false;
				break;
			}
			else
			{
				a--;
				if (s[i] == '?') s[i] = s[j];
				else s[j] = s[i];
			}

		}
		else if ((s[i] == '1' && s[j] == '?') || (s[i] == '?' && s[j] == '1'))
		{
			if (b < 1)
			{
				ans = false;
				break;
			}
			else
			{
				b--;
				if (s[i] == '?') s[i] = s[j];
				else s[j] = s[i];
			}
		}
	}
	for (int i = 0, j = s.size() - 1; i <= j; ++i, j--)
	{
		if (i == j && s[i] == '?')
		{
			if (a < 1 && b < 1)
			{
				ans = false;
				break;
			}
			if (a > b)
			{
				s[i] = '0'; s[j] = '0';
				a--;
			}
			else
			{
				s[i] = '1'; s[j] = '1';
				b--;
			}
		}
		else if (s[i] == '?' && s[j] == '?')
		{
			if (a < 2 && b < 2)
			{
				ans = false;
				break;
			}
			if (a > b)
			{
				s[i] = '0'; s[j] = '0';
				a -= 2;
			}
			else
			{
				s[i] = '1'; s[j] = '1';
				b -= 2;
			}
		}

	}
	if (ans)
	{
		string t = s;
		reverse(s.begin(), s.end());
		if (s == t)
		{
			cout << s << endl;
		}
		else
		{
			cout << -1 << endl;
		}

	}
	else
	{
		cout << -1 << endl;
	}

}


int main()
{
	faster;
	iofun();
	test;
	return 0;
}