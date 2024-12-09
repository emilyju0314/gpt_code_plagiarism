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

    set<int> ans;
    for (int i = 0; i < (1 << n); i++) {
        int xor_val = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                xor_val ^= a[j];
            }
        }
        ans.insert(xor_val);
    }

    cout << ans.size() << endl;
    for (auto num : ans) {
        cout << num << " ";
    }

    return 0;
}