#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> program(m);
    for (int i = 0; i < m; i++) {
        cin >> program[i];
    }

    Point BP = {0, 0};
    Point DP = {0, 1};
    Point CP = {1, 0};

    for (int step = 1; step <= n; step++) {
        int color = program[BP.x][BP.y] - '0';

        Point edge = BP;
        while (edge.x >= 0 && edge.y >= 0 && edge.x < m && edge.y < program[edge.x].size() && program[edge.x][edge.y] == program[BP.x][BP.y]) {
            edge.x += DP.x;
            edge.y += DP.y;
        }
        edge.x -= DP.x;
        edge.y -= DP.y;

        Point next = edge;
        while (next.x >= 0 && next.y >= 0 && next.x < m && next.y < program[next.x].size() && program[next.x][next.y] == program[edge.x][edge.y]) {
            Point new_next = {next.x + DP.x, next.y + DP.y};
            if (new_next.x >= 0 && new_next.y >= 0 && new_next.x < m && new_next.y < program[new_next.x].size() && program[new_next.x][new_next.y] == program[next.x][next.y]) {
                next = new_next;
            } else {
                break;
            }
        }

        if (program[next.x][next.y] == '0' || next.x < 0 || next.y < 0 || next.x >= m || next.y >= program[next.x].size()) {
            if (CP.x == 1) {
                DP.x = -DP.y;
                DP.y = DP.x;
            } else {
                CP.x = 1;
                CP.y = 0;
            }
        } else {
            BP = next;
        }
    }

    cout << program[BP.x][BP.y] - '0' << endl;

    return 0;
}