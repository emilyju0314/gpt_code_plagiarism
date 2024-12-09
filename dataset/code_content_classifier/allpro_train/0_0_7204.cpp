#include <iostream>
#include <algorithm>
#include <vector>

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
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int result = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int lcm = a[i] * a[j] / gcd(a[i], a[j]);
            if (result == 0) {
                result = lcm;
            } else {
                result = gcd(result, lcm);
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}