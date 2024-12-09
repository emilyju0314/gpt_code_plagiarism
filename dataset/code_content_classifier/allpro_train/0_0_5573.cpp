#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPossibility(vector<int>& q, vector<int>& s, int k) {
    int n = q.size();
    vector<int> p(n);
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        t[i] = i + 1;
    }

    for (int i = 0; i < k; i++) {
        if (p == s) {
            return true;
        }
        
        vector<int> new_p(n);
        if (rand() % 2 == 0) {
            for (int j = 0; j < n; j++) {
                new_p[j] = p[q[j] - 1];
            }
        } else {
            for (int j = 0; j < n; j++) {
                new_p[j] = t[q[j] - 1];
            }
        }
        p = new_p;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (checkPossibility(q, s, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}