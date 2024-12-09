#include <iostream>
using namespace std;

long long countIntegers(long long a, long long b, long long l, long long r) {
    long long ans = r - l + 1;
    long long numCyclesA = r / a - (l - 1) / a;
    long long numCyclesB = r / b - (l - 1) / b;
    long long numCyclesAB = r / (a * b) - (l - 1) / (a * b);
    
    long long ansValid = ans - (numCyclesA + numCyclesB - 2 * numCyclesAB);
    return ansValid;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long a, b, q;
        cin >> a >> b >> q;
        
        while(q--) {
            long long l, r;
            cin >> l >> r;
            cout << countIntegers(a, b, l, r) << " ";
        }
        cout << endl;
    }
    
    return 0;
}