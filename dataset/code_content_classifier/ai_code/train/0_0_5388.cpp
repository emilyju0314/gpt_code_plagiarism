#include <iostream>
#include <cmath>

using namespace std;

long long getMaxCoins(long long n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return (n - 1) / 2;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long maxCoins = getMaxCoins(N);
        cout << maxCoins << endl;
    }

    return 0;
}