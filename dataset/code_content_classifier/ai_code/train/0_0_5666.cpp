#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> peas(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> peas[i][j];
        }
    }
    
    int max_peas = -1, start_column = -1;
    string moves;
    int dx = k == 0 ? 1 : (k+1);
    
    for(int j = 0; j < m; j++) {
        int sum = peas[n-1][j];
        int current_column = j + 1;
        string current_moves;
        
        for(int i = n-1; i > 0; i--) {
            int left = j - dx;
            int right = j + dx;
            
            if(left >= 0 && peas[i-1][left] > peas[i-1][right]) {
                sum += peas[i-1][left];
                current_moves += 'L';
                j = left;
            } else {
                sum += peas[i-1][right];
                current_moves += 'R';
                j = right;
            }
        }
        
        if(sum % (k + 1) == 0 && sum > max_peas) {
            max_peas = sum;
            start_column = current_column;
            moves = current_moves;
        }
    }
    
    if(max_peas == -1) {
        cout << -1 << endl;
    } else {
        cout << max_peas << endl;
        cout << start_column << endl;
        cout << moves << endl;
    }
    
    return 0;
}