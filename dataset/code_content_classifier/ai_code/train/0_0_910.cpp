#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int len = arr.size() * T;
    vector<int> dp(len, 1);
    
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i % n] >= arr[j % n]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int maxLength = 0;
    for (int i = 0; i < len; i++) {
        maxLength = max(maxLength, dp[i]);
    }
    
    cout << maxLength << endl;
    
    return 0;
}