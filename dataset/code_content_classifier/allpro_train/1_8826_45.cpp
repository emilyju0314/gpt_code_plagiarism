#include <iostream>
#include <cstring>
#include <queue>
#include <cctype>
using namespace std;

struct State {
    int row, col, mask, floor, cost;
    State(int row, int col, int mask, int floor, int cost) :
        row(row), col(col), mask(mask), floor(floor), cost(cost) {}
};

const int MAX_W = 51;
const int MAX_H = 51;
const int MAX_S = 11;

bool valid[MAX_H][MAX_W][1 << MAX_S][2];
int cost[MAX_H][MAX_W][1 << MAX_S][2];

string m[MAX_H], ms[MAX_S][MAX_H];

int w, h, s;

int dr[4] = {1, 0, -1, 0},
    dc[4] = {0, 1, 0, -1};

void push_with_test(queue<State>& que, int nr, int nc, int nm, int nf, int ncost) {
    int& ref_cost = cost[nr][nc][nm][nf];
    if (valid[nr][nc][nm][nf] && ref_cost == -1) {
        ref_cost = ncost;
        que.push(State(nr, nc, nm, nf, ref_cost));
    }
}

int bfs(int sr, int sc) {
    queue<State> que;
    memset(cost, -1, sizeof(cost));

    cost[sr][sc][0][0] = 0;
    que.push(State(sr, sc, 0, 0, cost[sr][sc][0][0]));

    while (!que.empty()) {
        State st = que.front(); que.pop();

        if (m[st.row][st.col] == '&') {
            return st.cost;
        }

        // ??£??\????????????????§????
        for (int i = 0; i < 4; i++) {
            int nr = st.row + dr[i],
                nc = st.col + dc[i],
                nm = st.mask,
                nf = st.floor;
            push_with_test(que, nr, nc, nm, nf, st.cost + 1);
        }

        // ?????????????????????????????????????????´??????
        if (m[st.row][st.col] == '|') {
            int nr = st.row,
                nc = st.col,
                nm = st.mask,
                nf = (st.floor + 1) % 2;
            push_with_test(que, nr, nc, nm, nf, st.cost + 1);
        }

        // ?????????????????????????????????????????????????????????
        if (isalpha(m[st.row][st.col])) {
            char alpha = m[st.row][st.col];
            int alpha_i = isupper(alpha) ? (alpha - 'A') : (alpha - 'a'),
                nr = st.row,
                nc = st.col,
                nm = st.mask ^ (1 << alpha_i),
                nf = ms[alpha_i][st.row][st.col] == '*' ? (st.floor + 1) % 2 :
                                                                    st.floor;
            push_with_test(que, nr, nc, nm, nf, st.cost + 1);
        }
    }

    return -1;
}

int main() {
    cin >> w >> h;
    
    int sr, sc;
    for (int r = 0; r < h; r++) {
        cin >> m[r];
        for (int c = 0; c < w; c++) {
            if (m[r][c] == '%') {
                sr = r;
                sc = c;
                break;
            }
        }
    }

    cin >> s;
    for (int s_i = 0; s_i < s; s_i++) {
        for (int r = 0; r < h; r++) {
            cin >> ms[s_i][r];
        }
    }

    // valid????????????
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            for (int mask = 0; mask < (1 << s); mask++) {
                if (m[r][c] == '#') {
                    continue;
                } else if (m[r][c] == '|') {
                    valid[r][c][mask][0] = valid[r][c][mask][1] = true;
                    continue;
                }

                int init_floor = (isupper(m[r][c]) || m[r][c] == '^') ? 1 : 0,
                    move = 0;
                for (int s_i = 0; s_i < s; s_i++) {
                    if (((mask >> s_i) & 1) && ms[s_i][r][c] == '*') {
                        move++;
                    }
                }
                valid[r][c][mask][(init_floor + move) % 2] = true;
            }
        }
    }

    cout << bfs(sr, sc) << endl;

    return 0;
}