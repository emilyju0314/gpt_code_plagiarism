#include <iostream>
#include <vector>

using namespace std;

void moveTank(vector<string>& map, int& tankRow, int& tankCol, char move) {
    switch(move) {
        case 'U':
            if(tankRow > 0 && map[tankRow - 1][tankCol] == '.') {
                map[tankRow][tankCol] = '.';
                tankRow--;
            }
            break;
        case 'D':
            if(tankRow < map.size() - 1 && map[tankRow + 1][tankCol] == '.') {
                map[tankRow][tankCol] = '.';
                tankRow++;
            }
            break;
        case 'L':
            if(tankCol > 0 && map[tankRow][tankCol - 1] == '.') {
                map[tankRow][tankCol] = '.';
                tankCol--;
            }
            break;
        case 'R':
            if(tankCol < map[0].size() - 1 && map[tankRow][tankCol + 1] == '.') {
                map[tankRow][tankCol] = '.';
                tankCol++;
            }
            break;
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int H, W;
        cin >> H >> W;

        vector<string> map(H);
        int tankRow, tankCol;

        for(int i = 0; i < H; i++) {
            cin >> map[i];
            for(int j = 0; j < W; j++) {
                if(map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '<' || map[i][j] == '>') {
                    tankRow = i;
                    tankCol = j;
                }
            }
        }

        int N;
        cin >> N;

        string moves;
        cin >> moves;

        for(char move : moves) {
            switch(move) {
                case 'S':
                    switch(map[tankRow][tankCol]) {
                        case '^':
                            for(int i = tankRow - 1; i >= 0; i--) {
                                if(map[i][tankCol] == '*' || map[i][tankCol] == '#') {
                                    if(map[i][tankCol] == '*') {
                                        map[i][tankCol] = '.';
                                    }
                                    break;
                                }
                            }
                            break;
                        case 'v':
                            for(int i = tankRow + 1; i < H; i++) {
                                if(map[i][tankCol] == '*' || map[i][tankCol] == '#') {
                                    if(map[i][tankCol] == '*') {
                                        map[i][tankCol] = '.';
                                    }
                                    break;
                                }
                            }
                            break;
                        case '<':
                            for(int j = tankCol - 1; j >= 0; j--) {
                                if(map[tankRow][j] == '*' || map[tankRow][j] == '#') {
                                    if(map[tankRow][j] == '*') {
                                        map[tankRow][j] = '.';
                                    }
                                    break;
                                }
                            }
                            break;
                        case '>':
                            for(int j = tankCol + 1; j < W; j++) {
                                if(map[tankRow][j] == '*' || map[tankRow][j] == '#') {
                                    if(map[tankRow][j] == '*') {
                                        map[tankRow][j] = '.';
                                    }
                                    break;
                                }
                            }
                            break;
                    }
                    break;
                default:
                    moveTank(map, tankRow, tankCol, move);
                    break;
            }
        }

        for(auto row : map) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}