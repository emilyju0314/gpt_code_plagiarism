#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n, m, x;
        cin >> n >> m >> x;

        long long row = (x + n - 1) / n;
        long long col = (x % n == 0) ? n : x % n;

        long long result = (col - 1) * m + row;
        cout << result << endl;
    }

    return 0;
}