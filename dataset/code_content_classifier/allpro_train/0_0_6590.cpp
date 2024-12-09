#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n = 1 << k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    do {
        for (int i = 0; i < n; i++) {
            q[i] = p[i] ^ a[i];
        }

        sort(q.begin(), q.end());

        bool valid = true;
        for (int i = 0; i < n; i++) {
            if ((p[i] ^ q[i]) != a[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << "Shi" << endl;
            for (int i = 0; i < n; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "Fou" << endl;

    return 0;
}