#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        set<int> S;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            S.insert(a[i]);
        }

        int distinct_elements = n;

        int mex = 0, max_num = *S.rbegin();
        while (k--) {
            mex = 0;
            while (S.count(mex) != 0) {
                mex++;
            }
            int new_num = (mex + max_num + 1) / 2;
            S.insert(new_num);
            if (new_num > max_num) {
                max_num = new_num;
            }
            distinct_elements++;
        }

        cout << distinct_elements << endl;
    }

    return 0;
}