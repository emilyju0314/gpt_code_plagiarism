#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> field;

int getPoints(int x, int y) {
    int points = 1;
    char direction = field[x][y];

    field[x][y] = '.'; // Mark the current chip as removed

    if(direction == 'L') {
        while(y > 0 && field[x][y-1] != '.') {
            points++;
            y--;
        }
    } else if(direction == 'R') {
        while(y < m-1 && field[x][y+1] != '.') {
            points++;
            y++;
        }
    } else if(direction == 'U') {
        while(x > 0 && field[x-1][y] != '.') {
            points++;
            x--;
        }
    } else if(direction == 'D') {
        while(x < n-1 && field[x+1][y] != '.') {
            points++;
            x++;
        }
    }

    return points;
}

int main() {
    cin >> n >> m;

    field.resize(n, vector<char>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    int maxPoints = 0;
    int numMoves = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] != '.') {
                int points = getPoints(i, j);
                if(points > maxPoints) {
                    maxPoints = points;
                    numMoves = 1;
                } else if(points == maxPoints) {
                    numMoves++;
                }
            }
        }
    }

    cout << maxPoints << " " << numMoves << endl;

    return 0;
}