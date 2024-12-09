#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long m, x;
    cin >> m >> x;

    long long traps = 1;
    for (long long i = 2; i < m; i++) {
        if (gcd(i, m) == 1) {
            long long room = i;
            while (room != 0 && room != 1) {
                room = (room * x) % m;
                traps++;
            }
        }
    }

    cout << traps << endl;

    return 0;
}