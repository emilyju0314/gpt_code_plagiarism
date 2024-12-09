#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<int> lengths(q);
    for (int i = 0; i < q; i++) {
        cin >> lengths[i];
    }

    for (int i = 0; i < q; i++) {
        int max_length = -1;
        for (int j = 1; j <= x; j++) {
            if (x % j == 0) {
                bool valid = true;
                for (int k = 0; k <= n; k++) {
                    if (j % (x - a[k]) == 0 || j % a[k] == 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid && lengths[i] % j == 0) {
                    max_length = max(max_length, j);
                }
            }
        }
        cout << max_length << " ";
    }

    return 0;
}