#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << (i % n) + 1 << endl;
    }

    return 0;
}