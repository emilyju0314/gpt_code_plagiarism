#include <bits/stdc++.h>

using namespace std;
typedef set<int> si;
const int N=2e5+10;
int n; si a[N];
queue<si*> q;
priority_queue<int, vector<int>, greater<int> > vals;

si* smer (si* s, si* t) {
    if (s->size()<t->size()) swap(s,t);
    while (!t->empty()) {
        s->insert(*(t->begin()));
        t->erase(t->begin());
    }
    return s;
}

int main()
{/*
    freopen("input.txt","r",stdin); //*/
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) {
        int u; scanf("%d",&u);
        a[i].insert(u); vals.push(u);
    }
    for (int i=1; i<=n; ++i) {
        q.push(&a[i]);
    }
    long long ans = 0ll;
    while (!vals.empty()) {
        int u = vals.top(); vals.pop();
        si* dummy = q.front(); q.pop();
        while (!dummy->count(u)) {
            dummy = smer(dummy, q.front());
            q.pop();
        }
        dummy->erase(u);
        ans += dummy->size();
        if (!dummy->empty())
            q.push(dummy);
    }
    printf("%lld\n",ans);
    return 0;
}

