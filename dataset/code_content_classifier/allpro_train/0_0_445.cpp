#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        long long moves = 1LL * n * n - 1LL;
        cout << moves * (moves + 1) / 2 << endl;
    }
    
    return 0;
}