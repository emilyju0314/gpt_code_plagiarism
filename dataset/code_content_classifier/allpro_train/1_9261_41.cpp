#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <functional>
#include <cstdio>
#include <cmath>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
template <class T> bool setmax(T & l, T const & r) { if (not (l < r)) return false; l = r; return true; }
template <class T> bool setmin(T & l, T const & r) { if (not (r < l)) return false; l = r; return true; }
using namespace std;
const int inf = 1e9+7;
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
int main() {
    // input
    int w, h; cin >> w >> h;
    vector<string> c(h); repeat (y,h) cin >> c[y];
    // modify input
    int sy, sx, gy, gx;
    repeat (y,h) repeat (x,w) {
        if (c[y][x] == 's') {
            sy = y;
            sx = x;
            c[y][x] = '.';
        } else if (c[y][x] == 'g') {
            gy = y;
            gx = x;
        }
    }
    // prepare
    auto on_field = [&](int y, int x) { return 0 <= y and y < h and 0 <= x and x < w; };
    typedef queue<pair<int,int> > points_queue;
    auto bfs = [&](function<void (points_queue &)> init, function<void (points_queue &, int, int, int, int)> update) {
        points_queue que;
        init(que);
        while (not que.empty()) {
            int y, x; tie(y, x) = que.front(); que.pop();
            repeat (i,4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (not on_field(ny, nx)) continue;
                if (c[ny][nx] != '.') continue;
                update(que, y, x, ny, nx);
            }
        }
    };
    vector<vector<int> > goal(h, vector<int>(w, inf));
    bfs([&](points_queue & que) {
        goal[gy][gx] = 0;
        que.push(make_pair(gy, gx));
    }, [&](points_queue & que, int y, int x, int ny, int nx) {
        if (goal[ny][nx] == inf) {
            goal[ny][nx] = goal[y][x] + 1;
            que.push(make_pair(ny, nx));
        }
    });
    vector<vector<int> > jump(h, vector<int>(w, inf));
    bfs([&](points_queue & que) {
        repeat (y,h) repeat (x,w) if (c[y][x] == '*') {
            jump[y][x] = 0;
            que.push(make_pair(y, x));
        }
    }, [&](points_queue & que, int y, int x, int ny, int nx) {
        if (jump[ny][nx] == inf) {
            jump[ny][nx] = jump[y][x] + 1;
            que.push(make_pair(ny, nx));
        }
    });
    map<pair<int,int>,int> freq; // frequency
    int total = 0;
    int max_goal = 0;
    repeat (y,h) repeat (x,w) if (c[y][x] == '.') {
        freq[make_pair(goal[y][x], jump[y][x])] += 1;
        total += 1;
        if (goal[y][x] < inf) setmax(max_goal, goal[y][x]);
    }
    // calc
    long double e = INFINITY;
    repeat (estimate, max_goal + 1) {
        // E = f(E) = aE + b
        long double a = 0;
        long double b = 0;
        for (auto it : freq) {
            int g, s; tie(g, s) = it.first;
            int cnt = it.second;
            long double p = cnt /(long double) total;
            if (g == inf) {
                a += p;
                b += p * s;
            } else if (s == inf) {
                b += p * g;
            } else {
                if (g <= s + estimate) {
                    b += p * g;
                } else {
                    a += p;
                    b += p * s;
                }
            }
        }
        setmin(e, b / (1 - a));
    }
    // output
    long double ans
        = goal[sy][sx] == inf ? jump[sy][sx] + e
        : jump[sy][sx] == inf ? goal[sy][sx]
        : min<long double>(goal[sy][sx], jump[sy][sx] + e); // the answer can become grater than `int inf`, so conditional op. is required.
    printf("%.12Lf\n", ans);
    return 0;
}