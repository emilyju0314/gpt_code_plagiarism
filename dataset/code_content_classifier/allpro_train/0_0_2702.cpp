#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMergePossible(vector<int>& p, int n) {
    vector<bool> taken(2*n+1, false);

    vector<int> a, b;

    for (int i = 0; i < 2*n; i++) {
        if (!taken[p[i]]) {
            taken[p[i]] = true;
            if (a.empty() || a.back() < p[i]) {
                a.push_back(p[i]);
            } else if (b.empty() || b.back() < p[i]) {
                b.push_back(p[i]);
            } else {
                return false;
            }
        } else {
            if (a.back() == p[i]) {
                a.pop_back();
            } else if (b.back() == p[i]) {
                b.pop_back();
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(2*n);
        for (int i = 0; i < 2*n; i++) {
            cin >> p[i];
        }

        if (isMergePossible(p, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}