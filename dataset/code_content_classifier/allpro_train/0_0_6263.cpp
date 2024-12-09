#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            for (int j = 0; j < k; j++) {
                b[y-1+j] = a[x-1+j];
            }
        } else {
            int x;
            cin >> x;
            cout << b[x-1] << endl;
        }
    }

    return 0;
}