#include <bits/stdc++.h>
using namespace std;

vector <int> adia[100010];
int see[100010];
int maxim = 0, total;

int lsb(int x, int i)
{
    for (; ; i++)
        if ((1 << i) & x)
            return i;
}

int msb(int x)
{
    for (int i = 30; ; i--)
        if ((1 << i) & x)
            return i;
}

int dfs(int nod, int tata)
{
    int ce_pun = 0;
    for (auto i : adia[nod]) {
        if (i != tata) {
            int m = dfs(i, nod);
            if (m & see[nod])
                ce_pun = max(ce_pun, msb(m & see[nod]));
            see[nod] |= m;
        }
    }
    ce_pun = lsb(~see[nod], ce_pun);
    maxim = max(maxim, ce_pun);

    see[nod] |= (1 << ce_pun);
    for (int i = 0; i < ce_pun; i++)
        see[nod] &= ~(1 << i);

    return see[nod];
}

int main()
{
    int n, a, b;
    cin >> n;

    while (--n) {
        cin >> a >> b;
        adia[a].push_back(b);
        adia[b].push_back(a);
    }

    dfs(1, 0);

    cout << maxim << '\n';
}
