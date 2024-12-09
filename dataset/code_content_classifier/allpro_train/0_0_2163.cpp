#include <iostream>
#include <vector>

using namespace std;

int W, H;
vector<string> room;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H;
}

bool check(int x, int y, int dir) {
    while(true) {
        x += dx[dir];
        y += dy[dir];

        if(!isValid(x, y) || room[y][x] == '#') {
            return false;
        } else if(room[y][x] == 'D') {
            return true;
        } else if(room[y][x] == '*' || room[y][x] == 'S') {
            return false;
        }
    }
}

bool solve(int x, int y, int dir) {
    while(true) {
        x += dx[dir];
        y += dy[dir];

        if(!isValid(x, y) || room[y][x] == '#') {
            return false;
        } else if(room[y][x] == 'D') {
            return true;
        } else if(room[y][x] == '*' || room[y][x] == 'S') {
            return false;
        } else if(room[y][x] == '|' || room[y][x] == '-') {
            dir = (dir + 2) % 4;
        } else if(room[y][x] == '/') {
            dir = (dir + 1) % 4;
        } else if(room[y][x] == '\\') {
            dir = (dir + 3) % 4;
        } else if(room[y][x] == 'O') {
            return solve(x, y, (dir + 1) % 4) || solve(x, y, (dir + 3) % 4);
        }
    }
}

int main() {
    cin >> W >> H;

    room.resize(H);
    int startX, startY;

    for(int i = 0; i < H; i++) {
        cin >> room[i];
        for(int j = 0; j < W; j++) {
            if(room[i][j] == '@') {
                startX = j;
                startY = i;
            }
        }
    }

    bool possible = false;

    for(int i = 0; i < 4; i++) {
        if(check(startX, startY, i)) {
            possible = true;
            break;
        }
    }

    if(possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}