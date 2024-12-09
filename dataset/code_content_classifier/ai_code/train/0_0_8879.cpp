#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Starting number
    long long num = 2;

    for (long long i = 1; i <= n; i++) {
        // Determine the number of times to press the '+' button
        long long presses = (num + i - 1) / i * i - num;
        cout << presses << endl;

        // Update the number
        num += presses + i;
    }

    return 0;
}