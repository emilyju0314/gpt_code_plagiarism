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


class BipatiteGraph
{
    vector<bool> used;

    bool _dfs(int v)
    {
        used[v] = true;
        for (int i = 0; i < (int)edges[v].size(); ++i)
        {
            int u = edges[v][i];
            int k = match[u];
            if (k < 0 || (!used[k] && _dfs(k)))
            {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

public:
    int n, m;
    int vertices;
    vector<vector<int> > edges;
    vector<int> match;
    int matching;

    BipatiteGraph(int n, int m)
        : used(n + m), n(n), m(m), vertices(n + m), edges(n + m), match(n + m), matching(0)
    {
        clear();
    }

    void add_edge(int a, int b)
    {
        edges[a].push_back(b + n);
        edges[b + n].push_back(a);
    }

    void clear()
    {
        fill(match.begin(), match.end(), -1);
        matching = 0;
    }

    bool dfs(int v)
    {
        fill(used.begin(), used.end(), false);
        return _dfs(v);
    }

    int update_matching()
    {
        for (int i = 0; i < n; ++i)
            if (match[i] < 0 && dfs(i))
                ++matching;
        return matching;
    }

    int max_matching()
    {
        fill(match.begin(), match.end(), -1);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (match[i] < 0)
            {
                if (dfs(i))
                    ++res;
            }
        }
        return res;
    }
};
int main()
{
    int n, w[128], h[128];
    cin >> n;
    rep(i, n)
        cin >> w[i] >> h[i];

    BipatiteGraph g(n, n);
    rep(i, n) rep(j, n)
    {
        if ((w[i] > w[j] && h[i] > h[j]) ||
            (w[i] > h[j] && h[i] > w[j]))
        {
            g.add_edge(i, j);
        }
    }

    int res = n - g.max_matching();
    cout << res << endl;
}
