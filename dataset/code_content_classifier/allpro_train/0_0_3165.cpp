#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minTax = n; // initialize minTax to n

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            minTax = min(minTax, n / i);
        }
    }

    cout << minTax << endl;

    return 0;
}