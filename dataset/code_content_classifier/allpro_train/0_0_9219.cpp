#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<int> l(m);
    vector<int> r(m);
    vector<int> q(m);
    
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = l[i] - 1; j < r[i]; j++) {
            a[j] |= q[i];
        }
    }

    bool possible = true;
    for (int i = 0; i < m; i++) {
        for (int j = l[i] - 1; j < r[i]; j++) {
            if ((a[j] & q[i]) != q[i]) {
                possible = false;
                break;
            }
        }
    }
    
    if (possible) {
        cout << "YES" << endl;
        for (int num : a) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}