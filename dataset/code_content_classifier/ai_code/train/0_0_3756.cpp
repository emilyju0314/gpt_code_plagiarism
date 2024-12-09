#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int curr = n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && k > 0) {
            cout << curr-- << " ";
            k--;
        } else {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}