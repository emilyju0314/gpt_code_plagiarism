#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int      long long int
#define MOD      998244353
#define pb       push_back
#define pf       push_front
#define vi       vector<int>
#define mi       map<int,int>
#define umi      unordered_map<int,int>
#define pii      pair<int,int>
#define ff       first
#define ss       second
#define inf      1e18
#define case    int test;cin>>test;while(test--)
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int powm(int x, int y, int m = MOD) {
	x = x % m; int res = 1; while (y)
	{if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
int modi(int a, int m = MOD) {return powm(a, m - 2, m);}
void pre()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int32_t main()
{	pre();
case
	{
		string s;
		cin >> s;
		int x = 0, y = 0;
		vector<pii> v;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'L')
				x--;
			if (s[i] == 'R')
				x++;
			if (s[i] == 'U')
				y++;
			if (s[i] == 'D')
				y--;
			if (x != 0 || y != 0)
				v.pb({x, y});
		}
		int ax = 0, ay = 0;
		for (int i = 0; i < v.size(); i++)
		{
			int tx = 0, ty = 0;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == 'L')
				{	tx--;
					if (tx == v[i].ff && ty == v[i].ss)
						tx++;
				}
				if (s[j] == 'R')
				{	tx++;
					if (tx == v[i].ff && ty == v[i].ss)
						tx--;
				}
				if (s[j] == 'U')
				{	ty++;
					if (tx == v[i].ff && ty == v[i].ss)
						ty--;
				}
				if (s[j] == 'D')
				{	ty--;
					if (tx == v[i].ff && ty == v[i].ss)
						ty++;
				}
			}
			if (tx == 0 && ty == 0)
			{
				ax = v[i].ff;
				ay = v[i].ss;
				break;
			}
		}
		cout << ax << " " << ay << endl;
	}
	return 0;
}