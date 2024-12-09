#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int mod = 1e9 + 7;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int totient_function(int x) {
    int result = x;
    for(int i=2; i*i<=x; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
            }
            result -= result / i;
        }
    }
    if(x > 1) result -= result / x;
    return result % mod;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<q; i++) {
        string query;
        cin >> query;
        if(query == "MULTIPLY") {
            int l, r, x;
            cin >> l >> r >> x;
            for(int j=l-1; j<=r-1; j++) {
                arr[j] = (arr[j] * x) % mod;
            }
        } else if(query == "TOTIENT") {
            int l, r;
            cin >> l >> r;
            int product = 1;
            for(int j=l-1; j<=r-1; j++) {
                product = (product * arr[j]) % mod;
            }
            cout << totient_function(product) << endl;
        }
    }

    return 0;
}