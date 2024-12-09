#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int power(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (1LL * result * a) % m;
        }
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        int len = 0;
        int tmp = n;
        
        while (tmp > 0) {
            len++;
            tmp /= 10;
        }
        
        int ans = (1LL * len * power(10, m, mod) + n * m) % mod;
        cout << ans << endl;
    }
    
    return 0;
}