#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);

    // Perform at most 2n queries
    for (int i = 1; i <= n * 2; ++i) {
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            a[j] = rand() % n + 1;
        }

        cout << "? ";
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;

        cout.flush();

        int k;
        cin >> k;
        if (k == 0) {
            continue;
        }

        if (p[k - 1] == 0) {
            p[k - 1] = i;
        } else {
            break;
        }
    }

    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}