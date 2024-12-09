#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            swap(p[x-1], p[y-1]);
        } else if (t == 2) {
            int i, k;
            cin >> i >> k;
            for (int j = 0; j < k; j++) {
                i = p[i-1];
            }
            cout << i << endl;
        }
    }

    return 0;
}