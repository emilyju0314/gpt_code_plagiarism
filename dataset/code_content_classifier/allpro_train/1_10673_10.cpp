#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int>::max() / 2;
class seg
{
public:
    vector<int> tag;
    vector<int> Max;
    seg() {}
    seg(int N) : Max(N * 4 + 5, -Inf), tag(N * 4 + 5, 0) {}
    void pushdown(int x)
    {
        tag[x << 1] += tag[x];
        tag[x << 1 | 1] += tag[x];
        Max[x << 1] += tag[x];
        Max[x << 1 | 1] += tag[x];
        tag[x] = 0;
    }
    void add(int l, int r, int x, int a, int b, int v)
    {
        if (l > b || r < a)
        {
            return;
        }
        if (l >= a && r <= b)
        {
            tag[x] += v;
            Max[x] += v;
            return;
        }
        pushdown(x);
        int mid = l + r >> 1;
        add(l, mid, x << 1, a, b, v);
        add(mid + 1, r, x << 1 | 1, a, b, v);
        Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
    }
    void update(int l, int r, int x, int p, int v)
    {
        if (l == r)
        {
            Max[x] = max(Max[x], v);
            return;
        }
        int mid = l + r >> 1;
        pushdown(x);
        if (p <= mid)
        {
            update(l, mid, x << 1, p, v);
        }
        else
        {
            update(mid + 1, r, x << 1 | 1, p, v);
        }
        Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
    }
    int query(int l, int r, int x, int a, int b)
    {
        if (l > b || r < a)
        {
            return -Inf;
        }
        if (l >= a && r <= b)
        {
            return Max[x];
        }
        pushdown(x);
        int mid = l + r >> 1;
        return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N;
        cin >> N;
        vector<int> A(N * 2 + 1);
        A[0] = 0;
        for (int i = 1; i <= N; ++i)
        {
            cin >> A[i];
            //     A[i]--;
        }
        N++;
        vector<pair<int, int>> P;
        for (int i = 0; i < N; ++i)
        {
            P.emplace_back(A[i], i);
        }
        sort(P.begin(), P.end());
        vector<int> rnk(N);
        for (int i = 0; i < N; ++i)
        {
            rnk[P[i].second] = i;
        }
        vector<int> st;
        vector<int> nxt(N, -1);
        for (int i = 0; i < N; ++i)
        {
            while (!st.empty() && A[i] >= A[st.back()])
            {
                nxt[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        vector<vector<int>> add(N);
        for (int i = 0; i < N; ++i)
        {
            if (nxt[i] != -1)
            {
                add[nxt[i]].push_back(i);
            }
        }
        vector<int> dp(N * 2);
        seg seg(N);
        for (int i = 0; i < N; ++i)
        {
            dp[i] = max(1, seg.query(1, N, 1, 1, rnk[i] + 1) + 1);
            for (int j : add[i])
            {
                seg.add(1, N, 1, rnk[j] + 1, rnk[j] + 1, 1);
            }
            seg.update(1, N, 1, rnk[i] + 1, dp[i]);
        }
        int Ans = -Inf;
        for (int i = 0; i < N; ++i)
        {
            if (nxt[i] == -1)
            {
                Ans = max(Ans, dp[i]);
            }
            else
            {
                Ans = max(Ans, dp[i] + 1);
            }
        }
        cout << Ans - 1 << '\n';
    }
}