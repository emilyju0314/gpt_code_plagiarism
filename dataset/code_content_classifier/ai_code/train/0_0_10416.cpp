#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> b(n, -1);
        int mex = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mex) {
                b[i] = a[i];
                mex++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                b[i] = mex;
                mex++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}