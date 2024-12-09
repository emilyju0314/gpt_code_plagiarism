#include <iostream>

using namespace std;

int main() {
    long long m;
    cin >> m;

    long long n = -1;
    for (int i = 1; i <= 1000000; i++) {
        long long ways = 1;
        long long curr = i;

        while (ways < m) {
            curr *= 2;
            ways *= 3;
            if (ways >= m) {
                n = i;
                break;
            }
        }
        if (n != -1) {
            break;
        }
    }

    cout << n << endl;

    return 0;
}