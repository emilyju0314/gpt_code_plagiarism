#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int emptyPos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            emptyPos = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[(emptyPos + 1 + i) % n] == b[i]) {
            continue;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}