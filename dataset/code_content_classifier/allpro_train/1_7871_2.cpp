#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>

#ifdef LOCAL
#include "local.h"
#endif

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)
#define ten(n) ((long long)(1e##n))

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    char c[16][16];
    rep(y, h)
        cin >> c[y];

    vector<pint> start_imo(6);
    const char* imoimo = "Sabcde";
    rep(y, h) rep(x, w)
    {
        if (isalpha(c[y][x]))
            start_imo[strchr(imoimo, c[y][x]) - imoimo] = pint(x, y);
    }

    int res = -1;
    map<pair<int, vector<pint>>, int> dp;
    queue<pair<int, vector<pint>>> q;
    q.push(make_pair(0, start_imo));
    while (!q.empty())
    {
        const int esa = q.front().first;
        const vector<pint> imo = q.front().second;
        const int ncost = dp[q.front()] + 1;
        q.pop();
        assert(imo.size() == 6);

        rep(dir, 4)
        {
            int nx = imo[0].first + dx[dir];
            int ny = imo[0].second + dy[dir];
            if (in_rect(nx, ny, w, h) && c[ny][nx] != '#' &&
                count(imo.begin() + 1, imo.begin() + 5, pint(nx, ny)) == 0)
            {
                vector<pint> nimo;
                nimo.push_back(pint(nx, ny));
                rep(i, 5)
                    nimo.push_back(imo[i]);

                int nesa = esa;
                if (c[ny][nx] - '1' == esa)
                    ++nesa;

                if (nesa == n)
                {
                    res = ncost;
                    goto end;
                }

                auto next = make_pair(nesa, nimo);
                if (!dp.count(next))
                {
                    dp[next] = ncost;
                    q.push(next);
                }
            }
        }
    }
end:;
    cout << res << endl;
}
