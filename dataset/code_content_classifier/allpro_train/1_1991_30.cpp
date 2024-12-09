#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 4e5 + 5;
//（重复区间最大层数 - 1） * m +　重复区间最大层数区间的端点到数轴端点距离

ll n, m, L, R;
struct Interval
{
    ll l, r, cnt;
    bool operator<(const Interval cmp) const
    {
        return (this->l < cmp.l) || (this->l == cmp.l && this->cnt < cmp.cnt);
    }
} I[maxn];

ll res, max;
inline int bin_s(int p)
{
    int l = p, r = n;
    int res = p;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (I[mid].l <= I[p].r)
            l = mid + 1, res = mid;
        else
            r = mid - 1;
    }
    return res;
}

inline void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int tmp = bin_s(i), tmp2 = tmp - i + 1; //tmp -> pos tmp2 -> 层数
        if (tmp2 > max)
        {
            L = I[tmp].l, R = I[i].r;
            max = tmp2;
        }
        if (tmp2 == max)
        {
            L = std::min(L, I[tmp].l), R = std::max(R, I[i].r);
        }
        // printf("$%d %d %d %d %d\n", i, tmp,tmp2, L, R);
    }
}

inline void work()
{
    ll count = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        // printf("$%d ", i);
        ll p = i, a = 0, d = 0;
        while (I[p].l == I[p + 1].l)
            p++;
        for (int j = i; j <= p; j++)
            if (I[j].cnt == 1)
                a++;
            else
                d++;
        i = p;
        count += a;
        // printf("%d \n", count);
        if (count % 2)
            res = std::max(res, 1ll * (count - 1) * m + I[i].l);
        else
            res = std::max(res, 1ll * count * m - I[i].l);
        count -= d;
    }
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &I[i].l, &I[i + n].l), I[i].cnt = 1, I[i + n].cnt = -1;
    std::sort(I + 1, I + 2 * n + 1);
    //solve();
    work();
    // res = 1ll * (max - 1) * m;
    // if (max % 2 == 0) res += 1ll * m - L;
    // else res += R;
    std::cout << res << std::endl;
}
