#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> field;
vector<vector<bool>> visited;
int maxPoints, numMoves;

void dfs(int i, int j, int& currPoints) {
    visited[i][j] = true;
    currPoints++;

    switch(field[i][j]) {
        case 'L':
            if(j > 0 && field[i][j-1] != '.' && !visited[i][j-1]) {
                dfs(i, j-1, currPoints);
            }
            break;
        case 'R':
            if(j < m-1 && field[i][j+1] != '.' && !visited[i][j+1]) {
                dfs(i, j+1, currPoints);
            }
            break;
        case 'U':
            if(i > 0 && field[i-1][j] != '.' && !visited[i-1][j]) {
                dfs(i-1, j, currPoints);
            }
            break;
        case 'D':
            if(i < n-1 && field[i+1][j] != '.' && !visited[i+1][j]) {
                dfs(i+1, j, currPoints);
            }
            break;
    }
}

int main() {
    cin >> n >> m;

    field.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    maxPoints = 0;
    numMoves = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] != '.' && !visited[i][j]) {
                int currPoints = 0;
                dfs(i, j, currPoints);
                if(currPoints > maxPoints) {
                    maxPoints = currPoints;
                    numMoves = 1;
                } else if(currPoints == maxPoints) {
                    numMoves++;
                }
            }
        }
    }

    cout << maxPoints << " " << numMoves << endl;

    return 0;
}