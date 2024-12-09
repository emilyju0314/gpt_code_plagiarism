#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result = n;
    for (long long i = 2; i*i <= n; i++) {
        if (n % (i*i) == 0) {
            result = n / (i*i);
            break;
        }
    }

    cout << result << endl;

    return 0;
}