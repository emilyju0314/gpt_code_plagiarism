#include <iostream>

using namespace std;

int main() {
    long long s;
    cin >> s;

    long long count = 0;
    for (long long u = 1; u <= s; u++) {
        long long v = 2 * u + s;
        long long sum = (u + v) * (v - u + 1) / 2;
        if (sum == s) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}