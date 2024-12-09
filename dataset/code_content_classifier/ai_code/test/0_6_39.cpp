#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), s(n), cnt(n+1);

    for (int i = 1; i <= n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = j+1;
        }

        cout << "? ";
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        cout.flush();

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            s[j] = x - a[j];
            cnt[s[j]]++;
        }
    }

    for (int j = 0; j < n; j++) {
        if (cnt[s[j]] == 2) {
            p[j] = s[j];
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}