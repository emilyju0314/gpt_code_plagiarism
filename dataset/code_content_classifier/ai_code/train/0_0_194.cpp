#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long max_lcm = 1;

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    if (n % 2 == 0) {
        if (n % 3 == 0) {
            max_lcm = (long long)(n-1) * (n-2) * (n-3);
        } else {
            max_lcm = (long long)n * (n-1) * (n-3);
        }
    } else {
        max_lcm = (long long)n * (n-1) * (n-2);
    }

    cout << max_lcm << endl;

    return 0;
}