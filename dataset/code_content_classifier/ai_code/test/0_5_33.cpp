#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> possible_xor_values;
    for (int mask = 0; mask < (1 << 10); mask++) {
        int xor_val = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                xor_val ^= a[i];
            }
        }
        possible_xor_values.insert(xor_val);
    }

    cout << possible_xor_values.size() << endl;
    for (int val : possible_xor_values) {
        cout << val << " ";
    }

    return 0;
}