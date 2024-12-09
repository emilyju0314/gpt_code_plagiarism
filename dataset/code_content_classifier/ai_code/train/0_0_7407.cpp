#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << (i * (i + 1) * (i + 1)) - 1 << "\n";
    }

    return 0;
}