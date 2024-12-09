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

        vector<int> p(n);
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> negIdx;
        vector<int> posIdx;

        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (p[i] - 1 > i) {
                negIdx.push_back(i);
            } else if (p[i] - 1 < i) {
                posIdx.push_back(i);
            } else {
                possible = false;
            }
        }

        if (!possible) {
            cout << "NO" << endl;
        } else {
            for (int i = 0; i < negIdx.size(); i++) {
                a[negIdx[i]] = -(i + 1);
            }

            for (int i = 0; i < posIdx.size(); i++) {
                a[posIdx[i]] = i + 1;
            }

            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}