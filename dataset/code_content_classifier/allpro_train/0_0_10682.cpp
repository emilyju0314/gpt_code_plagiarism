#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 1;
        for (int i = 2; i <= n; ++i) {
            cout << " " << i;
        }
    } else {
        cout << -1;
    }

    return 0;
}