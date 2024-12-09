#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        if (a[i] >= 0 && a[i] == a[i-1] + 1) {
            dp[i] = dp[i-1] + 1;
        }
    }
    
    int maxLen = 0;
    int endIdx = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIdx = i;
        }
    }
    
    if (maxLen == 0) {
        cout << "0" << endl;
    } else {
        cout << maxLen << endl;
        for (int i = endIdx - maxLen + 1; i <= endIdx; i++) {
            cout << 2000 + i + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}