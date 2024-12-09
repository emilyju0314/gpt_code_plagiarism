#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> pii;

const int maxn = 100005;
int bubble[maxn][2];
int nextBubble[maxn], res[maxn];

inline int cross(pii A, pii B) {
    return A.first * B.second - A.second * B.first;
}

void main() {
    int n;
    cin >> n;
    forn(i, n) {
        cin >> bubble[i][0] >> bubble[i][1];
    }

    vector<int> p(n);
    iota(all(p), 0);
    sort(all(p), [](int i, int j) {
        return make_pair(bubble[i][0], bubble[i][1]) < make_pair(bubble[j][0], bubble[j][1]);
    });

    for (int i = 0; i < n - 1; i++) {
        nextBubble[p[i]] = p[i + 1];
    }
    nextBubble[p[n - 1]] = p[0];

    int q;
    cin >> q;
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        
        pii v = {x, y};
        int finalBubble = *max_element(p.begin(), p.end(), [&](int i, int j) {
            return cross({bubble[i][0] - bubble[j][0], bubble[i][1] - bubble[j][1]}, v) < 0;
        });

        if (cross({x, y}, {bubble[finalBubble][0], bubble[finalBubble][1]}) == 0) {
            cout << finalBubble + 1 << endl;
        } else {
            int cur = finalBubble;
            while (k--) {
                cur = nextBubble[cur];
            }
            cout << cur + 1 << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    main();
    return 0;
}