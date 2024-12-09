#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        char sheet[2000][2000];
        bool rowCheck[2000];
        bool colCheck[2000];

        for(int i = 0; i < n; i++) {
            cin >> sheet[i];
        }

        memset(rowCheck, false, sizeof(rowCheck));
        memset(colCheck, false, sizeof(colCheck));
        
        vector<pair<pair<int, int>, pair<int, int>>> snakes;
        int snakeCount = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(sheet[i][j] != '.') {
                    int row = i, col = j;
                    while(row < n && sheet[row][j] != '.') {
                        row++;
                    }
                    while(col < m && sheet[i][col] != '.') {
                        col++;
                    }

                    if(row - i == 1 && !colCheck[j]) {
                        snakeCount++;
                        rowCheck[i] = true;
                        colCheck[j] = true;
                        snakes.push_back({{i, j}, {i, j}});
                    } else if(col - j == 1 && !rowCheck[i]) {
                        snakeCount++;
                        rowCheck[i] = true;
                        colCheck[j] = true;
                        snakes.push_back({{i, j}, {i, j}});
                    }
                }
            }
        }

        bool possible = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(sheet[i][j] != '.' && !rowCheck[i] && !colCheck[j]) {
                    possible = false;
                }
            }
        }

        if(possible) {
            cout << "YES\n";
            cout << snakeCount << "\n";
            for(auto snake: snakes) {
                cout << snake.first.first + 1 << " " << snake.first.second + 1 << " " << snake.second.first + 1 << " " << snake.second.second + 1 << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}