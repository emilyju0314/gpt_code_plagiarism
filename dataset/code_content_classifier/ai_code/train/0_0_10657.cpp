#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> doors(n);
    for (int i = 0; i < n; i++) {
        cin >> doors[i];
    }

    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (x <= doors[i]) {
            zero_count++;
        }
    }

    if (x > y) {
        cout << n << endl;
    } else {
        if (zero_count % 2 == 0) {
            cout << zero_count / 2 << endl;
        } else {
            cout << (zero_count + 1) / 2 << endl;
        }
    }

    return 0;
}