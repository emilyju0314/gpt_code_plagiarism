#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), ans(n);
    vector<int> count(n+1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = j+1;
            if (i == j+1) a[j] = n;
        }

        cout << "? ";
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        cout.flush();

        int k;
        cin >> k;

        if (k != 0) count[k]++;
    }

    int max_count = *max_element(count.begin(), count.end());
    int idx = find(count.begin(), count.end(), max_count) - count.begin();

    for (int j = 0; j < n; j++) ans[j] = (j == idx-1) ? n : idx;

    cout << "! ";
    for (int j = 0; j < n; j++) {
        cout << ans[j] << " ";
    }
    cout << endl;

    return 0;
}