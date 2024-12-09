#include <iostream>
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
    
    vector<int> b(n);
    b[0] = a[0];
    int sum = b[0];
    
    for (int i = 1; i < n; i++) {
        b[i] = 1;
        sum++;
    }
    
    cout << b[0];
    for (int i = 1; i < n; i++) {
        cout << " " << b[i];
    }
    cout << endl;
    
    return 0;
}