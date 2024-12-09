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
        int x = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                x ^= a[j];
            }
        }
        ans.insert(x);
    }

    cout << ans.size() << endl;
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}