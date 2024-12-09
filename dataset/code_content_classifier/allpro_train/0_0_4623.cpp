#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> table(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char cell;
            cin >> cell;
            table[i][j] = cell - '0';
        }
    }
    
    int count = 0;
    
    for(int i1 = 0; i1 < n; i1++) {
        for(int i2 = i1; i2 < n; i2++) {
            int ones = 0;
            for(int j = 0; j < m; j++) {
                for(int i = i1; i <= i2; i++) {
                    ones += table[i][j];
                }
                if(ones == k) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}