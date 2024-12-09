#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate the period of spots for both cats
        long long periodA = n + n - 2; // napping spots for cat A
        long long periodB = n - 1; // napping spots for cat B

        // Calculate where cat B will be at hour k
        k = k % periodA;
        if(k == 0) {
            cout << n << endl; // Cat A is napping at spot n
        } else {
            if(k % n == 0) {
                cout << n << endl; // Cat B is napping at spot n
            } else {
                cout << k % n << endl;
            }
        }
    }

    return 0;
}