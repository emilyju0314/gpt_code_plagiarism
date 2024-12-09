#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int count = 1;
            int cur = p[i];
            while (cur != i) {
                cur = p[cur];
                count++;
            }
            ans[i] = count;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}