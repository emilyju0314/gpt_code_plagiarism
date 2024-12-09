#include <iostream>
#include <vector>
#include <cmath>

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
    
    vector<int> result(n);
    result[0] = sqrt(table[0] * table[1] / table[n]);
    
    for (int i = 1; i < n; i++) {
        result[i] = table[i] / result[0];
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}