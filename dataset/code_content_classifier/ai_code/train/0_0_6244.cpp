#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int gcd = 0;
    for (int i = 0; i < n; i++) {
        gcd = __gcd(gcd, a[i]);
    }
    
    if (gcd == 1) {
        cout << -1 << endl;
    } else {
        long long moves = 0;
        for (int i = 0; i < n; i++) {
            moves += a[i] / gcd;
        }
        cout << moves << endl;
    }
    
    return 0;
}