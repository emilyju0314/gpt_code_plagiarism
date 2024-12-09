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

    set<int> x_values;

    for (int mask = 0; mask < (1 << n); mask++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                x ^= a[i];
            }
        }
        x_values.insert(x);
    }

    cout << x_values.size() << endl;
    for (int x : x_values) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}