#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct C {
    int x;
    int y;
    int r;
    bool operator<(const C& c) const
    {
        return r < c.r;
    }
};

inline bool contain(const C& c, const int x, const int y)
{
    return hypot(c.x - x, c.y - y) < c.r;
}

inline bool contain(const C& c1, const C& c2)  // c1 < c2
{
    return hypot(c1.x - c2.x, c1.y - c2.y) + c1.r < c2.r;
}

inline bool separate(const C& c1, const C& c2)
{
    return hypot(c1.x - c2.x, c1.y - c2.y) > c1.r + c2.r;
}

struct Graph {
    Graph(const int n)
    {
        edge.resize(n);
    }
    void addEdge(const int from, const int to)
    {
        edge[from].push_back(to);
    }
    vector<vector<int>> edge;
};


int main()
{
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        vector<C> s;
        vector<C> t;
        for (int i = 0; i < N; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            C c{x, y, r};
            const bool S = contain(c, sx, sy);
            const bool T = contain(c, gx, gy);
            if (S and not T) {
                s.push_back(c);
            }
            if (T and not S) {
                t.push_back(c);
            }
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        const int S = s.size();
        const int T = t.size();
        Graph sg(S + 1);
        Graph tg(T + 1);
        for (int i = 1; i <= S; i++) {
            sg.addEdge(0, i);
        }
        for (int i = 1; i <= S; i++) {
            for (int j = i + 1; j <= S; j++) {
                if (contain(s[i - 1], s[j - 1])) {
                    sg.addEdge(i, j);
                }
            }
        }
        for (int i = 1; i <= T; i++) {
            tg.addEdge(0, i);
        }
        for (int i = 1; i <= T; i++) {
            for (int j = i + 1; j <= T; j++) {
                if (contain(t[i - 1], t[j - 1])) {
                    tg.addEdge(i, j);
                }
            }
        }
        vector<int> sdp(S + 1, 0);
        vector<int> tdp(T + 1, 0);
        int smax = 0;
        for (int i = 0; i <= S; i++) {
            for (const int to : sg.edge[i]) {
                sdp[to] = max(sdp[to], sdp[i] + 1);
                smax = max(smax, sdp[to]);
            }
        }
        int tmax = 0;
        for (int i = 0; i <= T; i++) {
            for (const int to : tg.edge[i]) {
                tdp[to] = max(tdp[to], tdp[i] + 1);
                tmax = max(tmax, tdp[to]);
            }
        }
        int ans = max(smax, tmax);
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < T; j++) {
                if (separate(s[i], t[j])) {
                    ans = max(ans, sdp[i + 1] + tdp[j + 1]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

