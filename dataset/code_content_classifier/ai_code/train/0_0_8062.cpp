#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countValidFlags(int n, int m, vector<vector<char>>& blanket) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char topColor = blanket[i][j];
            for (int k = i+1; k < n; k++) {
                char midColor = blanket[k][j];
                for (int l = k+1; l < n; l++) {
                    char botColor = blanket[l][j];
                    if (topColor != midColor && midColor != botColor) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> blanket(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> blanket[i][j];
        }
    }
    
    int result = countValidFlags(n, m, blanket);
    cout << result << endl;
    
    return 0;
}