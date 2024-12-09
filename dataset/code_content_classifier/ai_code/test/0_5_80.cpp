#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());

        long long cnt = 0;
        for(int i = 0; i < m; i++) {
            cnt += lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        }

        cout << cnt << endl;
    }

    return 0;
}