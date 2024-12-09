#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // If n is even, the numbers a and b will be n/2
        if(n % 2 == 0) {
            cout << n/2 << " " << n/2 << endl;
        } else {
            // If n is odd, we can choose a = 1 and b = n-1
            cout << 1 << " " << n-1 << endl;
        }
    }

    return 0;
}