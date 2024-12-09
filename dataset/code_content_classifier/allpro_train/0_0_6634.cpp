#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    
    int white_sets = 0, black_sets = 0;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            count += table[i][j];
        }
        if (count > 1) {
            white_sets += 1 << count;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += table[i][j];
        }
        if (count > 1) {
            black_sets += 1 << count;
        }
    }
    
    int total_sets = white_sets + black_sets - n*m;
    cout << total_sets << endl;
    
    return 0;
}