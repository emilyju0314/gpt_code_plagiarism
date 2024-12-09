#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSplit(vector<int>& a) {
    vector<int> lis(a.size(), 1);
    for(int i = 1; i < a.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(a[j] < a[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int xor_result = 0;
    for(int length : lis) {
        xor_result ^= length;
    }
    return xor_result == 0;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(canSplit(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}