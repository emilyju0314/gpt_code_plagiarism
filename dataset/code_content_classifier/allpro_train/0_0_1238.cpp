#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int lcm_val = (a[i] * a[j]) / gcd(a[i], a[j]);
            if (ans == 0) {
                ans = lcm_val;
            } else {
                ans = gcd(ans, lcm_val);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}