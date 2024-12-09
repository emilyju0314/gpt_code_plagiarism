#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
    } else {
        cout << log2(n) + 1 << endl;
    }

    return 0;
}