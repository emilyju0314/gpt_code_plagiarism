#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> stamp;
    constexpr char color[] = {'R', 'G', 'B'};
    vector<int> h(N), w(N);
    for(int i=0; i<N; ++i) {
        cin >> h[i] >> w[i];
    }

    string g;
    for(int i=0; i<16; ++i) {
        char c;
        cin >> c;
        g += c;
    }

    for(int i=0; i<N; ++i) {
        for(int y=-h[i]+1; y<4; ++y) {
            for(int x=-w[i]+1; x<4; ++x) {
                for(int c=0; c<3; ++c) {
                    int flag1 = (1 << 16) - 1;
                    int flag2 = 0;
                    for(int k=0; k<h[i]; ++k) {
                        for(int l=0; l<w[i]; ++l) {
                            int yy = (y+k)*4, xx = x+l;
                            if(yy < 0 && 16 <= yy || xx < 0 || 4 <= xx || 16 <= yy+xx) {
                                continue;
                            }
                            if(color[c] == g[yy+xx]) {
                                flag2 |= (1 << (yy+xx));
                            } else {
                                flag1 &= ~(1 << (yy+xx));
                            }
                        }
                    }
                    stamp.push_back(make_pair(flag1, flag2));
                }
            }
        }
    }
    sort(stamp.begin(), stamp.end());
    stamp.erase(unique(stamp.begin(), stamp.end()), stamp.end());

    queue<int> que;
    vector<int> dp(1 << 16, INF);
    dp[0] = 0;
    que.push(0);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto& s : stamp) {
            int next = (now & s.first) | s.second;
            if(dp[next] == INF) {
                dp[next] = dp[now] + 1;
                que.push(next);
            }
        }
    }
    cout << dp[(1 << 16) - 1] << endl;
}
