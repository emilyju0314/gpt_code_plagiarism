#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        long long k, x;
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
    
    return 0;
}