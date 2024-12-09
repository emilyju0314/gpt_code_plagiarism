#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            if ((j & -j) == j) {
                sum -= j;
            } else {
                sum += j;
            }
        }

        cout << sum << endl;
    }

    return 0;
}