#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int max_m = a[0];
    for(int l = 0; l <= k; l++) {
        for(int r = 0; r <= k; r++) {
            if(l + r <= k && l < n && r < n) {
                int m = b[n-1-r] + a[l];
                if(l != n-1) m = max(m, b[n-1-r] + b[l+1] - b[l] + a[l]);
                max_m = max(max_m, m);
            }
        }
    }
    
    cout << max_m << endl;
    
    return 0;
}