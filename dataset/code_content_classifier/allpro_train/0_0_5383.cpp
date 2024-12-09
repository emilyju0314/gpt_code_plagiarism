#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    map<int, int> count;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }
    
    int max_cols = 0, max_rows = 0;
    for(auto &iter : count) {
        max_cols = max(max_cols, iter.second);
        max_rows++;
    }
    
    cout << max_rows * max_cols << endl;
    cout << max_rows << " " << max_cols << endl;
    
    vector<vector<int>> matrix(max_rows, vector<int>(max_cols, 0));
    
    int col = 0;
    for(auto &iter : count) {
        for(int i = 0; i < iter.second; i++) {
            matrix[i][col] = iter.first;
            col = (col + 1) % max_cols;
        }
    }
    
    for(int i = 0; i < max_rows; i++) {
        for(int j = 0; j < max_cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}