#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 1; i <= n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = j + 1;
        }

        cout << "? ";
        random_shuffle(a.begin(), a.end());
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        cout << flush;

        int k;
        cin >> k;

        if (k != 0) {
            p[k-1] = i;
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}