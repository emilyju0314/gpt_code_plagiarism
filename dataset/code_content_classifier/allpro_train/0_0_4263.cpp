#include <iostream>
#include <vector>

using namespace std;

int f(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        while (k--) {
            n += f(n);
        }

        cout << n << endl;
    }

    return 0;
}