#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_lcm = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_lcm = max(max_lcm, lcm(a[i], a[j]));
        }
    }
    
    cout << max_lcm << endl;
    
    return 0;
}