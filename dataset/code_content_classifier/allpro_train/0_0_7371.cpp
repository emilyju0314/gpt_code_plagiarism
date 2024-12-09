#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    int p = 1, q = 1;
    for(int i = sqrt(n); i >= 1; i--) {
        if(n % i == 0) {
            p = n / i;
            q = i;
            break;
        }
    }
    
    int k = 0;
    vector<vector<int>> matrix(p, vector<int>(q, 0));
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            matrix[i][j] = nums[k++];
        }
    }
    
    cout << n << endl;
    cout << p << " " << q << endl;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}