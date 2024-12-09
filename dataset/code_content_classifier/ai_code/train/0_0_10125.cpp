#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
    int kr, kc, pr, pc, moves;
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int main() {
    int H, W;

    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;

        vector<vector<char>> frame(H, vector<char>(W));
        int kr, kc, pr1, pc1, pr2, pc2;

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> frame[i][j];
                if (frame[i][j] == 'o') {
                    if (pr1 == -1) {
                        pr1 = i;
                        pc1 = j;
                    } else {
                        pr2 = i;
                        pc2 = j;
                    }
                }
                if (frame[i][j] == 'X') {
                    kr = i;
                    kc = j;
                }
            }
        }

        queue<State> q;
        vector<vector<vector<vector<int>>> dist(H, vector<vector<vector<int>>>(W, vector<vector<int>>(H, vector<int>(W, -1))));
        q.push({kr, kc, pr1, pc1, 0});
        dist[kr][kc][pr1][pc1] = 0;

        int ans = -1;

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            if (curr.kr == 0 && curr.kc == 0) {
                ans = curr.moves;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                State next = curr;

                int nkr = next.kr + dr[i];
                int nkc = next.kc + dc[i];
                int npr1 = next.pr + dr[i];
                int npc1 = next.pc + dc[i];
                int npr2 = next.pr - dr[i];
                int npc2 = next.pc - dc[i];

                if (nkr < 0 || nkr >= H || nkc < 0 || nkc >= W) continue;
                if (frame[nkr][nkc] == '*') continue;

                if (dist[nkr][nkc][npr1][npc1] == -1) {
                    dist[nkr][nkc][npr1][npc1] = next.moves + 1;
                    q.push({nkr, nkc, npr1, npc1, next.moves + 1});
                }
                if (dist[nkr][nkc][npr2][npc2] == -1) {
                    dist[nkr][nkc][npr2][npc2] = next.moves + 1;
                    q.push({nkr, nkc, npr2, npc2, next.moves + 1});
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}