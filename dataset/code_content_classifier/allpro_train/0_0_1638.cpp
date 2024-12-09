#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> points(n, vector<int>(4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> points[i][j];
        }
    }
    
    char direction;
    cin >> direction;
    
    for (int i = 0; i < n; i++) {
        if (direction == 'N') {
            if (points[i][0] == points[i][2] && points[i][1] == points[i][3]) {
                cout << points[i][0] << " " << points[i][1] << endl;
            }
        } else {
            // Update for other directions (E, W, S) if needed
        }
    }
    
    return 0;
}