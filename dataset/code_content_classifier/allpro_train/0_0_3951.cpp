#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long n, k;
    cin >> n >> k;
    
    if (k > n || k == 1) {
        cout << -1 << endl;
        return 0;
    }
    
    long long g = 1;
    for (int i = 1; i < k; i++) {
        cout << i << " ";
        g = gcd(g, i);
    }
    
    cout << n - g * (k - 1) << endl;
    
    return 0;
}