#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long h = ceil((2 * k) / (2.0 * (n + 1)));

    cout << h << endl;

    return 0;
}