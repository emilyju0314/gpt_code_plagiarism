#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define int long long
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define all(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
const int INF = 1e9;

struct Data {
    int rem, t, c;
    bool operator<(const Data &a) const { return rem < a.rem; }
};
bool solve() {
    int N;
    cin >> N;
    if (N == 0) return false;
    vector<int> C(N), T(N);
    vector<pii> v(N);
    REP(i, N) {
        cin >> T[i] >> C[i];
        C[i]--;
        v[i] = {T[i], C[i]};
    }
    vector<deque<Data>> deq(2);
    sort(all(v));
    int sum = 0;
    REP(i, N) { deq[0].push_back({v[i].first, v[i].first, v[i].second}); }
    while (true) {
        if (deq[0].empty() && deq[1].empty()) break;
        bool go = true;
        int mn = 1e9;
        if (!deq[0].empty()) {
            mn = min(mn, deq[0].front().rem);
                }
        if (!deq[1].empty()) mn = min(mn, deq[1].front().rem);
        if (deq[0].empty()) go = false;
        if (!deq[1].empty() && deq[1].front().rem < deq[0].front().rem) go = false;
        vector<Data> nxtret, nxtgo;
        if (true) {
            while (!deq[0].empty()) {
                Data d = deq[0].front();
                if (d.rem > mn) break;
                deq[0].pop_front();
                nxtret.push_back({d.t, d.t, d.c});
            }
            REP(i, deq[0].size()) { deq[0][i].rem -= mn; }
            while (!deq[1].empty()) {
                Data d = deq[1].front();
                if (d.rem > mn) break;
                deq[1].pop_front();
                if (d.c) nxtgo.push_back({d.t, d.t, d.c - 1});
            }
            REP(i, deq[1].size()) { deq[1][i].rem -= mn; }
            sort(all(nxtgo));
            sort(all(nxtret));
            for (auto d : nxtgo) {
                deq[0].push_back(d);
            };
            for (auto d : nxtret) {
                deq[1].push_back(d);
            }
            sum += mn;
        }
    }
    cout << sum << endl;
    return true;
}

signed main() {
    while (solve())
        ;
}

