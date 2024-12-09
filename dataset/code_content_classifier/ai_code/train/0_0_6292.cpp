#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if(n == 0) {
        cout << 0 << endl;
    } else {
        cout << (n % 2 == 0 ? (n / 2) * 3 : (n + 1) / 2) << endl;
    }

    return 0;
}