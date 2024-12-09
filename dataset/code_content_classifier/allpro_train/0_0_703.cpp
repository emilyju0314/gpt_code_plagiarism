#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> display(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            display[i][j] = row[j] - '0';
        }
    }
    
    int commands = 0;
    vector<vector<int>> prefixSums(n+1, vector<int>(n+1, 0));
    
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            prefixSums[i][j] = prefixSums[i+1][j] + prefixSums[i][j+1] - prefixSums[i+1][j+1] + display[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    int sum = prefixSums[i][j] - prefixSums[i][l+1] - prefixSums[k+1][j] + prefixSums[k+1][l+1];
                    if (sum == 0 || sum == (k - i + 1) * (l - j + 1)) {
                        commands++;
                    }
                }
            }
        }
    }
    
    cout << commands << endl;
    
    return 0;
}