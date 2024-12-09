#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        long long int ans = abs(r1 - r2) + abs(c1 - c2);
        ans = min(ans, 1LL * abs(r1 - r2) + (long long)abs(c1 - a[r1-1]) + abs(a[r1-1] - c2));
        ans = min(ans, 1LL * abs(r1 - r2) + (long long)abs(c1 - 0) + abs(0 - c2));
        ans = min(ans, 1LL * abs(c1 - c2) + (long long)abs(r1 - r2));
        ans = min(ans, (long long)abs(c1 - a[r1-1]) + abs(a[r1-1] - c2) + (long long)abs(r1 - r2));
        ans = min(ans, (long long)abs(c1 - a[r1-1]) + abs(a[r1-1] - c2) + (long long)abs(r1 - r2));

        cout << ans << endl;
    }
    
    return 0;
}