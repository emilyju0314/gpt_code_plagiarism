#include <iostream>
using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;

    while (p--) {
        // Read query xi
        int xi;
        cin >> xi;

        // Determine if the slot should be empty or charged
        // Print "." if empty and "X" if charged
        if ((k == 0) || (xi > n - k)) {
            cout << ".";
        } else {
            cout << "X";
        }
    }

    return 0;
}