#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int q;
    cin >> q;

    vector<int> a;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int u;
            cin >> u;
            a.push_back(u);
        } else {
            int x, k, s;
            cin >> x >> k >> s;

            int max_xor = -1;
            int res = -1;
            
            for (int j = 0; j < a.size(); j++) {
                if (k % gcd(x, a[j]) == 0 && x + a[j] <= s) {
                    int cur_xor = x ^ a[j];
                    if (cur_xor > max_xor) {
                        max_xor = cur_xor;
                        res = a[j];
                    }
                }
            }
            
            cout << res << endl;
        }
    }

    return 0;
}