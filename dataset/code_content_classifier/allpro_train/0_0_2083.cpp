#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long b;
    cin >> b;

    long long result = 0;

    for (long long i = 1; i <= sqrt(b); i++) {
        if (b % i == 0) {
            result++;
            if (b / i != i) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}