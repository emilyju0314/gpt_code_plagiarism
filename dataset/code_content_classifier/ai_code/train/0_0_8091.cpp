#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for(int j = l-1; j < r; j++) {
                sum += a[j];
            }
            cout << sum << endl;
        } else if(type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            for(int j = l-1; j < r; j++) {
                a[j] %= x;
            }
        } else {
            int k, x;
            cin >> k >> x;
            a[k-1] = x;
        }
    }

    return 0;
}