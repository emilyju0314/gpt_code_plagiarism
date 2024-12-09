#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int g = gcd(a[i], a[j]);
            int p = gcd(i+1, j+1);
            result = (result + (long long)g * p) % MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}