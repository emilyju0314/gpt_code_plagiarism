#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << endl;
    } else {
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    }

    return 0;
}