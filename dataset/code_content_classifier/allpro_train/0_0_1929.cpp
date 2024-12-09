#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;
        
        int ans = 0;
        while (a > 0) {
            if (b == 1) {
                ans += a;
                break;
            } else if (b > a) {
                ans += a - 1;
                break;
            } else {
                long long q = a / b;
                long long r = a % b;
                ans += q;
                a = q + r;
                b++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}