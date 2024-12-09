#include <iostream>
using namespace std;

int main() {
    int k, b, n, t;
    cin >> k >> b >> n >> t;

    int bacteria = t;
    int seconds = 0;

    while (bacteria < n) {
        bacteria = k*bacteria + b;
        seconds++;
    }

    cout << seconds << endl;

    return 0;
}