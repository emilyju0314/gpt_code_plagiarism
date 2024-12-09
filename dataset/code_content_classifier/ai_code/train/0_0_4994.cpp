#include <iostream>

using namespace std;

string isFiniteFraction(long long p, long long q, long long b) {
    long long gcd;
    while ((gcd = __gcd(p, q)) != 1) {
        p /= gcd;
        q /= gcd;
    }
    while ((gcd = __gcd(q, b)) != 1) {
        q /= gcd;
    }
    if (q == 1) {
        return "Finite";
    } else {
        return "Infinite";
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long long p, q, b;
        cin >> p >> q >> b;
        
        string result = isFiniteFraction(p, q, b);
        cout << result << endl;
    }
    
    return 0;
}