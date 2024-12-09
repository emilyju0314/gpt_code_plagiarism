#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long n, m, p;
    cin >> n >> m >> p;
    
    vector<int> passwords;
    for (int i = 0; i < m; i++) {
        if (i == p % m) continue;
        
        bool valid = true;
        for (int j = 2; j <= sqrt(m); j++) {
            if (m % j == 0 && (p % j == i || p % (m / j) == i)) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            passwords.push_back(i);
        }
    }
    
    if (passwords.size() < n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << passwords[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}