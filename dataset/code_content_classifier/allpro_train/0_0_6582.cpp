#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> M;

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 0) {
            string key;
            int x;
            cin >> key >> x;
            if (M.count(key) == 0) {
                M[key] = x;
            }
        } else if (op == 1) {
            string key;
            cin >> key;
            if (M.count(key) == 0) {
                cout << 0 << endl;
            } else {
                cout << M[key] << endl;
            }
        } else if (op == 2) {
            string key;
            cin >> key;
            M.erase(key);
        } else if (op == 3) {
            string L, R;
            cin >> L >> R;
            for (auto it = M.lower_bound(L); it != M.upper_bound(R); ++it) {
                cout << it->first << " " << it->second << endl;
            }
        }
    }

    return 0;
}