#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int len = pow(2, n) - 1; // Length of the sequence after n steps

    while (k > 1) {
        int midpoint = len / 2 + 1; // Position of the midpoint
        if (k == midpoint) {
            cout << n << endl;
            break;
        } else {
            if (k > midpoint) {
                k -= midpoint; // Move to the second half of the sequence
            }
            len = (len - 1) / 2; // Update the length of the sequence
            n--; // Decrement n
        }
    }

    return 0;
}