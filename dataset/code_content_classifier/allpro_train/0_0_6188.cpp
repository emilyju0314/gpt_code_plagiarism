#include <iostream>
#include <vector>
#include <algorithm>
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
    
    vector<int> table(n*n);
    for (int i = 0; i < n*n; i++) {
        cin >> table[i];
    }
    
    sort(table.begin(), table.end());
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = table[i*n];
    }
    
    for (int i = 1; i < n; i++) {
        a[i] = table[i];
        for (int j = 0; j < i; j++) {
            a[i] = gcd(a[i], a[j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}