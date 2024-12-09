#include <iostream>
#include <vector>
#define sz(x) (int)x.size()
using namespace std;

int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> av, bv;
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                ++cnt1;
            }
            else {
                ++cnt0;
            }
            av.push_back(a[i] - '0');
            bv.push_back(b[i] - '0');
        }
        bool isrev = 0;
        bool ans = 1;
        for (int i = n - 1; i >= 0; --i) {
            int old = av[i];
            if (isrev) {
                av[i] = !av[i];
            }
            if (av[i] != bv[i]) {
                if (cnt1 == cnt0) {
                    isrev = !isrev;
                }
                else {
                    ans = 0;
                }
            }
            if (old == 1) {
                --cnt1;
            }
            else {
                --cnt0;
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
       
    }
}