#include <iostream>
#include <vector>

using namespace std;

long long power(long long x, long long n, long long mod) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return result;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long t = 0;
    for (int i = 0; i < n; i++) {
        t = (t + arr[i]) % 1000000007;
    }
    t = (t * x) % 1000000007;

    long long s = power(x, n, 1000000007);
    
    long long result = gcd(s, t);
    cout << result << endl;

    return 0;
}