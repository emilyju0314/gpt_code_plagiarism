#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    sort(b.begin(), b.end()); // Sort array b in ascending order
    
    for(int i = 0; i < n; i++) {
        c[i] = (a[i] + b[i]) % n; // Calculate c_i according to the given formula
    }
    
    for(int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    
    return 0;
}