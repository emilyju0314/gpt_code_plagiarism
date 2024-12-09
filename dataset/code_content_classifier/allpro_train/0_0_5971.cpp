#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

#define N 4

struct State {
    int board[N][N];
    int spaceX, spaceY;
    int depth;

    bool operator<(const State& s) const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != s.board[i][j]) {
                    return board[i][j] < s.board[i][j];
                }
            }
        }
        return false;
    }
};

int solve(State start) {
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    const char dir[4] = {'d', 'r', 'u', 'l'};

    queue<State> q;
    map<State, int> depth;

    q.push(start);
    depth[start] = 0;

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (depth[s] > 45) {
            return -1;
        }

        if (s.board[0][0] == 1 && s.board[0][1] == 2 && s.board[0][2] == 3 && s.board[0][3] == 4 
            && s.board[1][0] == 5 && s.board[1][1] == 6 && s.board[1][2] == 7 && s.board[1][3] == 8
            && s.board[2][0] == 9 && s.board[2][1] == 10 && s.board[2][2] == 11 && s.board[2][3] == 12
            && s.board[3][0] == 13 && s.board[3][1] == 14 && s.board[3][2] == 15 && s.board[3][3] == 0) {
            return s.depth;
        }

        for (int i = 0; i < 4; i++) {
            State next = s;
            int nextX = s.spaceX + dx[i];
            int nextY = s.spaceY + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) {
                continue;
            }

            swap(next.board[s.spaceY][s.spaceX], next.board[nextY][nextX]);
            next.spaceX = nextX;
            next.spaceY = nextY;
            next.depth = s.depth + 1;

            if (depth.count(next) == 0 || depth[next] > next.depth) {
                depth[next] = next.depth;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    State start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> start.board[i][j];
            if (start.board[i][j] == 0) {
                start.spaceX = j;
                start.spaceY = i;
            }
        }
    }

    start.depth = 0;

    int steps = solve(start);
    cout << steps << endl;

    return 0;
}