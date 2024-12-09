#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int max_sum = 0;
        for (int j = 0; j < m; j++) {
            vector<int> column_values;
            for (int i = 0; i < n; i++) {
                column_values.push_back(matrix[i][j]);
            }
            sort(column_values.begin(), column_values.end(), greater<int>());
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += column_values[i];
            }
            max_sum = max(max_sum, sum);
        }
        
        cout << max_sum << endl;
    }
    
    return 0;
}