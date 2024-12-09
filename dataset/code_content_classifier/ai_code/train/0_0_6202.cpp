#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        long long cumulativePower = 1;
        for (int j = l - 1; j < r; j++) {
            cumulativePower = (cumulativePower * powers[j]) % m;
        }

        cout << cumulativePower << endl;
    }

    return 0;
}