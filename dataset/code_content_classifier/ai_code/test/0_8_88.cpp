#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSplitIntoSubarrays(vector<int>& a) {
    int n = a.size();
    
    // Calculate the LIS lengths
    vector<int> lis(n);
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    // Calculate the XOR of LIS lengths
    int xorLIS = 0;
    for (int i = 0; i < n; i++) {
        xorLIS ^= lis[i];
    }
    
    return xorLIS == 0;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (canSplitIntoSubarrays(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}