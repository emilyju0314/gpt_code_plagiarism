#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(2 * n);

    for (int i = 0; i < 2 * k; i++) {
        if (i % 2 == 0) {
            a[i] = i / 2 + 1;
        } else {
            a[i] = n + i / 2 + 1;
        }
    }

    for (int i = 2 * k; i < 2 * n; i++) {
        a[i] = i - 2 * k + 1;
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}