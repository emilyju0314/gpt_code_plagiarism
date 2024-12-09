#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Position {
    int x, y;
};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> board(H);
    Position start, goal;

    for (int i = 0; i < H; i++) {
        cin >> board[i];
        size_t found_s = board[i].find('s');
        if (found_s != string::npos) {
            start = {found_s, i};
        }
        size_t found_g = board[i].find('g');
        if (found_g != string::npos) {
            goal = {found_g, i};
        }
    }

    string program;
    cin >> program;

    // Parse and execute the program
    int actions_executed = 0;
    Position curr_pos = start;
    char dir = 'N';

    for (char action : program) {
        if (action == '^') {
            Position next = curr_pos;
            switch (dir) {
                case 'N':
                    next.y--;
                    break;
                case 'E':
                    next.x++;
                    break;
                case 'S':
                    next.y++;
                    break;
                case 'W':
                    next.x--;
                    break;
            }
            if (next.x >= 0 && next.x < W && next.y >= 0 && next.y < H && board[next.y][next.x] != '#') {
                curr_pos = next;
                actions_executed++;
            }
        } else if (action == 'v') {
            Position next = curr_pos;
            switch (dir) {
                case 'N':
                    next.y++;
                    break;
                case 'E':
                    next.x--;
                    break;
                case 'S':
                    next.y--;
                    break;
                case 'W':
                    next.x++;
                    break;
            }
            if (next.x >= 0 && next.x < W && next.y >= 0 && next.y < H && board[next.y][next.x] != '#') {
                curr_pos = next;
                actions_executed++;
            }
        } else if (action == '<') {
            if (dir == 'N') dir = 'W';
            else if (dir == 'E') dir = 'N';
            else if (dir == 'S') dir = 'E';
            else if (dir == 'W') dir = 'S';
        } else if (action == '>') {
            if (dir == 'N') dir = 'E';
            else if (dir == 'E') dir = 'S';
            else if (dir == 'S') dir = 'W';
            else if (dir == 'W') dir = 'N';
        }
        if (curr_pos.x == goal.x && curr_pos.y == goal.y) {
            break;
        }
    }

    if (curr_pos.x == goal.x && curr_pos.y == goal.y) {
        cout << actions_executed << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}