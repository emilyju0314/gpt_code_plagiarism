#include <iostream>
#include <vector>
using namespace std;

bool solvePuzzle(vector<vector<int>>& puzzle, int n) {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(puzzle[i][j] < 0) {
                int target = puzzle[i][j];
                for(vector<int>& direction : directions) {
                    int x = i + direction[0];
                    int y = j + direction[1];
                    int sum = puzzle[i][j];
                    while(x >= 0 && x < n && y >= 0 && y < n) {
                        sum += puzzle[x][y];
                        if(sum == target) break;
                        x += direction[0];
                        y += direction[1];
                    }
                    if(sum != target) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        
        vector<vector<int>> puzzle(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> puzzle[i][j];
            }
        }
        
        if(solvePuzzle(puzzle, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}