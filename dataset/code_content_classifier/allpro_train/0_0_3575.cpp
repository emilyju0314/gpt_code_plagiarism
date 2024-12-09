#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> numbers;
    for (int i = 0; i < n; i++) {
        numbers.insert(a[i]);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1 || t == 2 || t == 3) {
            int l, r, x;
            cin >> l >> r >> x;

            for (int j = 0; j < n; j++) {
                if (a[j] >= l && a[j] <= r) {
                    if (t == 1) {
                        a[j] = a[j] & x;
                    } else if (t == 2) {
                        a[j] = a[j] | x;
                    } else if (t == 3) {
                        a[j] = a[j] ^ x;
                    }
                }
            }

            numbers.clear();
            for (int j = 0; j < n; j++) {
                numbers.insert(a[j]);
            }
        } else if (t == 4) {
            int l, r;
            cin >> l >> r;

            int count = 0;
            for (int num : numbers) {
                if (num >= l && num <= r) {
                    count++;
                }
            }

            cout << count << endl;
        }
    }

    return 0;
}