#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, vector<int>> M;
    vector<pair<string, int>> elements;

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 0) {
            string key;
            int x;
            cin >> key >> x;
            M[key].push_back(x);
            elements.push_back({key, x});
        } else if (op == 1) {
            string key;
            cin >> key;
            for (int val : M[key]) {
                cout << val << endl;
            }
        } else if (op == 2) {
            string key;
            cin >> key;
            M[key].clear();
        } else {
            string L, R;
            cin >> L >> R;
            for (auto element : elements) {
                if (element.first >= L && element.first <= R) {
                    cout << element.first << " " << element.second << endl;
                }
            }
        }
    }

    return 0;
}