#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

template <class T, class U>
inline bool chmax(T& t, const U& f) { return t < f ? t = f, true : false; }

const int d[] = {1, -1, -1, 1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    map<pair<int, int>, int> fox;
    rep(i, N) {
        int x, y, w; cin >> x >> y >> w;
        fox[make_pair(x, y)] = w;
    }
    int maxi = 0;
    for (const auto& e : fox) {
        pair<int, int> t; int x1, y1, w;
        tie(t, w) = e; tie(x1, y1) = t;
        rep(k, 4) {
            w = e.second;
            int x2 = x1 + d[k], y2 = y1 + d[(k + 1) % 4];
            t = make_pair(x2, y2);
            if (fox.count(t)) w += fox[t];
            t = make_pair(x1, y2);
            if (fox.count(t)) w += fox[t];
            t = make_pair(x2, y1);
            if (fox.count(t)) w += fox[t];
            chmax(maxi, w);
        }
    }
    cout << maxi << " / 1" << endl;
}