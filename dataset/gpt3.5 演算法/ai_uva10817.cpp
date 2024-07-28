#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    int p;

    while (cin >> n >> p) {
        if (n == 0 && p == 0) {
            break;
        }

        long long ans = (long long)(log(p) / log(n));
        cout << ans << endl;
    }

    return 0;
}
