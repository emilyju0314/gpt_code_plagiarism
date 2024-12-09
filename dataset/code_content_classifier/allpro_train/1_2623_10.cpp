#include <bits/stdc++.h>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;
 
#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define EACH(it, a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define MP make_pair

int f(VInt p, VInt s)
{
	int n = SIZE(p);
	int left = 0, right = n - 1;
	int res = 0;
	VInt used(n, 0);
	while(left < right)
	{
		int cnt = 0;
		int flips = 0;
		int l = left;
		int r = right + 1;
		while(l >= left || r <= right)
		{
			if(l >= left)
			{
				int a = left;
				++left;
				if(used[a] == 0)
				{
					int b = p[a];
					used[a] = used[b] = 1;
					++cnt;
					flips += s[a];
					if(b > r) return -1;
					r = b;
					if(l >= r) return -1;
				}
			}
			if(r <= right)
			{
				int a = right;
				--right;
				if(used[a] == 0)
				{
					int b = p[a];
					used[a] = used[b] = 1;
					++cnt;
					flips += s[a];
					if(b < l) return -1;
					l = b;
					if(l >= r) return -1;
				}
			}
		}
		res += min(flips, cnt - flips);
	}
	return res;
}

void SolveTest(int test)
{
	int n;
	cin >> n;
	int i, j;
	VInt p(n + n);
	VInt s(n + n);
	FOR(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		p[a] = b;
		p[b] = a;
		s[a] = 0;
		s[b] = 1;
	}

	cout << f(p, s) << endl;
}

int main()
{
	int T, t;
	T = 1;
	//cin >> T;
	FOR(t, 0, T) SolveTest(t);
	return 0;
};