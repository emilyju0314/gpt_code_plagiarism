#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); ++i)
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int h, w;

inline bool inrect(int x, int y){
    return 0 <= x && x < h && 0 <= y && y < w;
}

int solve(vector<string>& a, char c){
    int res = 0;
    rep(i, h)rep(j, w)if(a[i][j] == c){
        rep(k, 4){
            int sx = i + dx[k], sy = j + dy[k];
            if(!inrect(sx, sy) || a[sx][sy] != '.')continue;
            a[sx][sy] = c;
            bool ok = true;
            int cnt = 0;
            queue<pair<int, int> > q;
            for(q.emplace(sx, sy); !q.empty();){
                int x = q.front().first, y = q.front().second; q.pop();
                cnt++;
                rep(l, 4){
                    int nx = x + dx[l], ny = y + dy[l];
                    if(!inrect(nx, ny))continue;
                    if(a[nx][ny] == '.'){
                        a[nx][ny] = c;
                        q.emplace(nx, ny);
                    }
                    else if(a[nx][ny] != c)ok = false;
                }
            }
            if(ok)res += cnt;
        }
    }
    return res;
}

int main(){
    while(cin >> w >> h, w|h){
        vector<string> a(h);
        rep(i, h)cin >> a[i];
        cout << solve(a, 'B') << " " << solve(a, 'W') << '\n';
    }
    return 0;
}