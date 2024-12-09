#include <iostream>

using namespace std;

int main() {
    long long a, b;
    int k;
    cin >> a >> b >> k;

    long long seconds = 0;

    while (a != b) {
        if (a < b) {
            seconds += (b - a);
            break;
        } else {
            seconds++;
            long long min_value = a - a % k;
            a = min(a - min_value, a - 1);
        }
    }

    cout << seconds << endl;

    return 0;
}