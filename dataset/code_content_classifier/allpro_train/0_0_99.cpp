#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isSubsequence(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set(arr2.begin(), arr2.end());
    
    for (int num : arr1) {
        if (set.find(num) != set.end()) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        if (isSubsequence(a, b)) {
            cout << "YES" << endl;
            cout << 1 << " " << a[0] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}