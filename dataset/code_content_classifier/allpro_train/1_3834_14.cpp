/// Monarchuwu
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
/// IO

#include <unordered_map>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
/// Data Structure

#include <algorithm>
#include <cstdlib>
#include <numeric>
/// Algorithm

#include <climits>
#include <cstring>
#include <cmath>
/// C library

#include <ctime>
#include <chrono>
#include <random>
/// Time

#define x first
#define y second
#define mp make_pair
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define filename "NAME"

using namespace std;
typedef long long ll;
typedef pair<double, double> point;

const int N = 507, oo = (int)1e9 + 7, mod[] = { (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277 };
bool a[N][N];
int m, n, prf[N][N];

signed main()
{
	ios_base::sync_with_stdio(false);
	int t, n, k; cin >> t;
	while (t-- > 0)
	{
		cin >> m >> n;
		char c;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
			{
				cin >> c;
				a[i][j] = (c == '*');
				prf[i][j] = prf[i][j - 1] + (a[i][j] ? 1 : 0);
			}

		int res = 0;
		for (int x = 1; x <= m; ++x)
			for (int y = 1; y <= n; ++y)
				for (int i = 1; x + i - 1 <= m && y - i + 1 > 0 && y + i - 1 <= n; ++i)
					if (prf[x + i - 1][y + i - 1] - prf[x + i - 1][y - i] == i * 2 - 1) ++res;
					else break;

		cout << res << '\n';
	}

	return 0;
}
