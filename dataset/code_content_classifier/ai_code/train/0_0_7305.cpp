#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> bags(n, vector<int>(n));
    
    int totalBags = n * n;
    int currentBag = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            bags[i][j] = currentBag++;
            bags[i][n - 1 - j] = currentBag++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << bags[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}