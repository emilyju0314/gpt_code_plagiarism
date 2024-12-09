#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // If n is even, we can choose a = n/2, b = n/2, c = 1
        if (n % 2 == 0) {
            cout << n/2 << " " << n/2 << " 1" << endl;
        } else {
            // If n is odd, we can choose a = n/2, b = n/2 - 1, c = 1
            cout << n/2 << " " << n/2 - 1 << " 1" << endl;
        }
    }

    return 0;
}