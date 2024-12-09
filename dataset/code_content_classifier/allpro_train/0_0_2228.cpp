#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> l(q), r(q), x(q);

    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }

    set<int> possible_max;

    for (int i = 0; i < (1 << q); i++) {
        vector<int> new_array(n, 0);

        for (int j = 0; j < q; j++) {
            if (i & (1 << j)) {
                for (int k = l[j] - 1; k <= r[j] - 1; k++) {
                    new_array[k] += x[j];
                }
            }
        }

        int max_val = 0;
        for (int val : new_array) {
            max_val = max(max_val, val);
        }

        possible_max.insert(max_val);
    }

    cout << possible_max.size() << endl;
    for (int val : possible_max) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}