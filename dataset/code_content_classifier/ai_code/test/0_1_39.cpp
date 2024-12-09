#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), a(n), s(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    for (int i = 0; i < 2*n; i++) {
        cout << "?";
        for (int j = 0; j < n; j++) {
            cout << " " << a[j];
        }
        cout << endl;
        cout.flush();

        int k;
        cin >> k;

        if (k == 0) {
            continue;
        }

        s[k-1]++;
        if (s[k-1] == 2) {
            cout << "!";
            for (int j = 0; j < n; j++) {
                p[j] = a[j];
                cout << " " << p[j];
            }
            cout << endl;
            break;
        }

        next_permutation(a.begin(), a.end());
    }

    return 0;
}