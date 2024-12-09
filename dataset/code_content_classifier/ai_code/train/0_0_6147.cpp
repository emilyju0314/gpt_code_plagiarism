#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<long long> a(n, 0);
    
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + (i == 0 ? 0 : a[(i - 1 + n) % n]);
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[(i + 1) % n] != (a[i] % b[i])) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}