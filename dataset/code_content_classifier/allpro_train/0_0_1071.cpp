#include <iostream>
using namespace std;

int main() {
    int k, b, n, t;
    cin >> k >> b >> n >> t;

    int bacteria = 0;
    int seconds = 0;

    while (seconds <= t && bacteria < n) {
        bacteria = k * bacteria + b;
        seconds++;
    }

    if (bacteria < n) {
        int remaining = n - bacteria;
        int additionalSeconds = remaining / k;
        if (remaining % k != 0) {
            additionalSeconds++;
        }
        seconds += additionalSeconds;
    }

    cout << seconds << endl;

    return 0;
}