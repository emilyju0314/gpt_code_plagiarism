#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct S{
    int x, y;
    int c, h;
    vector<int> cnt;
    bool operator < (const S& s) const {
        if(c + h != s.c + s.h) return c + h > s.c + s.h;
        return c > s.c;
    }
};

int main(){
    int W, H;
    while(cin >> W >> H && W){
        int sx, sy, gx, gy;
        vector<string> grid(H);
        REP(y, H) cin >> grid[y];
        REP(y, H) REP(x, W) if(grid[y][x] == 'S') { grid[y][x] = '.'; sx = x; sy = y; }
        REP(y, H) REP(x, W) if(grid[y][x] == 'G') { grid[y][x] = '.'; gx = x; gy = y; }

        int ice_count = 0;
        int ice_id[12][12] = {};
        vector<int> ice_v;
        REP(y, H) REP(x, W) if(grid[y][x] == 'X' && ice_id[y][x] == 0){
            ice_id[y][x] = ++ice_count;
            ice_v.push_back(1);
            queue<int> qx, qy;
            qx.push(x); qy.push(y);
            while(!qx.empty()){
                int bx = qx.front(); qx.pop();
                int by = qy.front(); qy.pop();
                REP(r, 4) {
                    int nx = bx + dx[r];
                    int ny = by + dy[r];
                    if(nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] == 'X' && ice_id[ny][nx] == 0){
                        qx.push(nx);
                        qy.push(ny);
                        ice_id[ny][nx] = ice_count;
                        ice_v[ice_count - 1]++;
                    }
                }
            }
        }

        int h_value[12][12];
        memset(h_value, -1, sizeof h_value);
        queue<int> qx, qy;
        qx.push(gx); qy.push(gy);
        h_value[gy][gx] = 0;
        while(!qx.empty()){
            int bx = qx.front(); qx.pop();
            int by = qy.front(); qy.pop();
            REP(r, 4) {
                int nx = bx + dx[r];
                int ny = by + dy[r];
                if(nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] != '#' && h_value[ny][nx] == -1){
                    qx.push(nx);
                    qy.push(ny);
                    h_value[ny][nx] = h_value[by][bx] + 1;
                }
            }
        }

        priority_queue<S> que;
        S init;
        init.x = sx, init.y = sy;
        init.cnt.resize(ice_count);
        init.c = 0; init.h = h_value[sy][sx];
        set<vector<int>> used[12][12];
        que.push(init);
        while(!que.empty()){
            S s = que.top(); que.pop();
            if(s.h == 0){
                cout << s.c << endl;
                break;
            }
            REP(r, 4){
                S next = s;
                next.x += dx[r]; next.y += dy[r];
                if(!(next.x >= 0 && next.x < W && next.y >= 0 && next.y < H && grid[next.y][next.x] != '#')) continue;
                next.c ++;
                next.h = h_value[next.y][next.x];
                int id = ice_id[next.y][next.x] - 1;
                if(id >= 0) next.cnt[id]++;
                if(id >= 0 && next.cnt[id] > ice_v[id] / 2) continue;
                if(used[next.y][next.x].count(next.cnt)) continue;
                used[next.y][next.x].insert(next.cnt);
                que.push(next);
            }
        }
    }
    return 0;
}