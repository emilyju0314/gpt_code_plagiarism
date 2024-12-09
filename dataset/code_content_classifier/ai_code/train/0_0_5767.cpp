#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    double ans = 0;
    for(int i = 0; i < n; i++) {
        ans += 1.0 * (i + 1) * (n - i);
    }
    ans /= n * n;
    
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}