#include <iostream>
#include <cmath>

using namespace std;

long long countWays(int n) {
    return pow(2, n) + (n % 2 == 0 ? 2 : 0);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        cout << countWays(n) << endl;
    }

    return 0;
}