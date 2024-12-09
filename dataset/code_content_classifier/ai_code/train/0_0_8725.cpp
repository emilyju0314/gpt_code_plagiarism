#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<vector<char>> grid(K, vector<char>(K, '.'));
    
    vector<pair<int, int>> desires;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        desires.push_back(make_pair(x, y));
        
        // Update the grid based on the color of the desire
        if (c == 'B') {
            grid[x % K][y % K] = 'B';
        } else {
            grid[x % K][y % K] = 'W';
        }
    }
    
    int blackCount = 0, whiteCount = 0;
    
    // Calculate the number of black and white squares in the grid
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (grid[i][j] == 'B') {
                blackCount++;
            } else if (grid[i][j] == 'W') {
                whiteCount++;
            }
        }
    }
    
    // Calculate the maximum number of desires that can be satisfied at the same time
    int maxDesires = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int currentDesires = 0;
            if (grid[i][j] == 'B') {
                currentDesires = blackCount - 1 + whiteCount;
            } else {
                currentDesires = blackCount + whiteCount - 1;
            }
            maxDesires = max(maxDesires, currentDesires);
        }
    }
    
    cout << maxDesires << endl;
    
    return 0;
}