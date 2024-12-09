#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e4 + 100;
long long a[N], b[N];

vector <pair <long long, long long> > v, nv;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i] );

	int ans = 0;
	long long x = 1;
	for (int it = 0; it < 17; it++)
	{
		long long x10 = x * 10;
		for (int i = 0; i < n; i++)
			b[i] = a[i] % x10;
	
		bool win = false;
		for (int d = 9; d >= 0; d--)
		{
			v.clear();
			v.emplace_back(x * d, x * (d + 1) - 1);
			if (d == 0) win = true;
			for (int i = 0; i < n && !win; i++)
			{
				nv.clear();
				for (auto p : v)
				{
					long long l = p.first - b[i], r = p.second - b[i];
					if (l < 0 && r >= 0)
					{
						win = true;
						break;
					}
					if (l < 0 && r < 0)
					{
						l += 10 * x;
						r += 10 * x;
					}
					nv.emplace_back(l, r);
					if (l == 0)
					{
						win = true;
						break;
					}
				}
				if (win) break;
				for (auto p : nv)
					v.push_back(p);
				sort(v.begin(), v.end() );
				nv.clear();
				long long l = -1, r = -1;
				for (auto p : v)
				{
					if (p.first > r)
					{
						if (l != -1)
							nv.emplace_back(l, r);
						l = p.first;
						r = p.second;
					}
					r = max(r, p.second);
				}
				nv.emplace_back(l, r);
				v = nv;
				nv.clear();
			}
			if (win)
			{
				ans += d;
				break;
			}
		}

		x *= 10;
	}
	printf("%d\n", ans);


	return 0;
}

