#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << "-1" << endl;
    } else {
        if (n % 2 == 0) {
            long long m = n / 2;
            long long k = m + 1;
            cout << m << " " << k << endl;
        } else {
            long long m = (n * n - 1) / 2;
            long long k = (n * n + 1) / 2;
            cout << m << " " << k << endl;
        }
    }

    return 0;
}