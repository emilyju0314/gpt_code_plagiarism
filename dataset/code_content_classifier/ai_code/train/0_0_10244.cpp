#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if ((a + b + c) % 9 == 0 && min({a, b, c}) >= (a + b + c) / 9) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
} 

// Sample Input
// 3
// 3 2 4
// 1 1 1
// 10 1 7

// Sample Output
// YES
// NO
// NO