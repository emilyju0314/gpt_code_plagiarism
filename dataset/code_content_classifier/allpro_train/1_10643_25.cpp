#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<P>> sub(5); // sub[i] := i曜日の(mask, 幸福)
    while (m--)
    {
        int d, a, k, t;
        cin >> d >> a >> k >> t;
        a--;
        int mask = 0;
        for (int i = a; i < a + k; i++)
            mask |= 1 << i;
        sub[d].push_back(P(mask, t));
    }
    // w[i][j] := i曜日にj個使うときの幸福最大
    vector<vector<int>> w(5, vector<int>(l + 1, -INF));
    for (int i = 0; i < 5; i++)
    {
        // dp[i][j] := i個でmask jでの幸福最大
        vector<vector<int>> dp(l + 1, vector<int>(1 << n, -INF));
        dp[0][0] = 0;
        for (auto p : sub[i])
        {
            int mask = p.first, t = p.second;
            for (int j = l - 1; j >= 0; j--)
            {
                for (int k = (1 << n) - 1; k >= 0; k--)
                {
                    if (dp[j][k] == -INF)
                        continue;
                    if (k & mask)
                        continue;
                    dp[j + 1][k | mask] = max(dp[j + 1][k | mask], dp[j][k] + t);
                }
            }
        }
        for (int j = 0; j <= l; j++)
        {
            for (int k = 0; k < (1 << n); k++)
            {
                w[i][j] = max(w[i][j], dp[j][k]);
            }
        }
    }
    // ret[i][j] := i日目まででj科目取る時の最大値
    vector<vector<int>> ret(5, vector<int>(l + 1, -INF));
    for (int j = 0; j <= l; j++)
        ret[0][j] = w[0][j];
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            for (int k = 0; k <= l; k++)
            {
                if (j - k < 0)
                    continue;
                ret[i][j] = max(ret[i][j], ret[i - 1][j - k] + w[i][k]);
            }
        }
    }
    int ma = 0;
    for (int j = 0; j <= l; j++)
        ma = max(ma, ret[4][j]);
    cout << ma << endl;
}

