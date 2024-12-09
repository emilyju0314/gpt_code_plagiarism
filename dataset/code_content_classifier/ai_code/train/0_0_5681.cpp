#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int p, k;
        cin >> p >> k;

        int operations = 0;
        while (p <= n) {
            p += a[p-1] + k;
            operations++;
        }

        cout << operations << endl;
    }

    return 0;
}