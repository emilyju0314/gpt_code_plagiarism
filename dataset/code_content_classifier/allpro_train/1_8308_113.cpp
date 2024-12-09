/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.07.13 02:11:35
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0) {
            break;
        }
        vector<string> s(h),t(h);
        pair<int,int> s_goal,t_goal,s_start,t_start;
        for (int i = 0; i < h; i++) {
            cin >> s[i] >> t[i];
            for (int j = 0; j < w; j++) {
                if (s[i][j] == '%') s_goal = {i,j};
                if (t[i][j] == '%') t_goal = {i,j};
                if (s[i][j] == 'L') s_start = {i,j};
                if (t[i][j] == 'R') t_start = {i,j};
            }
        }
        vector<vector<vector<vector<int>>>> dist(h,vector<vector<vector<int>>>(w,vector<vector<int>>(h,vector<int>(w,-1))));
        queue<tuple<int,int,int,int>> que;
        que.push(make_tuple(s_start.first,s_start.second,t_start.first,t_start.second));
        const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        bool ok = false;
        while(!que.empty()) {
            auto p = que.front(); que.pop();
            int sx = get<0>(p);
            int sy = get<1>(p);
            int tx = get<2>(p);
            int ty = get<3>(p);
            if (sx == s_goal.first && sy == s_goal.second && tx == t_goal.first && ty == t_goal.second) {
                ok = true;
                puts("Yes");
                break;
            }
            else if ((sx == s_goal.first && sy == s_goal.second) || (tx == t_goal.first && ty == t_goal.second)) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int x1 = sx + dx[i];
                int y1 = sy + dy[i];
                int x2 = tx + dx[i];
                int y2 = ty - dy[i];
                if (x1 >= 0 && x1 < h && y1 >= 0 && y1 < w && s[x1][y1] != '#') {
                }
                else {
                    x1 = sx, y1 = sy;
                }
                if (x2 >= 0 && x2 < h && y2 >= 0 && y2 < w && t[x2][y2] != '#') {
                }
                else {
                    x2 = tx, y2 = ty;
                }
                if (dist[x1][y1][x2][y2] == -1) {
                    que.push(make_tuple(x1,y1,x2,y2));
                    dist[x1][y1][x2][y2] = 0;
                }
            }
        }
        if (!ok) {
            puts("No");
        }
    }
    return 0;
}

