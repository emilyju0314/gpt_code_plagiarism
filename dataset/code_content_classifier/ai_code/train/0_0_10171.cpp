#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k >= n) {
        cout << -1 << endl;
    } else {
        int m = n * k;
        cout << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                cout << i+1 << " " << (i+j)%n+1 << endl;
            }
        }
    }
    
    return 0;
}