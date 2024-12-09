#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& a, vector<int>& b, int n, int m) {
    int i = 0, j = 0;
    long long inversions = 0;

    while (i < n) {
        if (j < m && b[j] < a[i]) {
            inversions += n - i;
            j++;
        } else {
            i++;
        }
    }

    return inversions;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << merge(a, b, n, m) << endl;
    }

    return 0;
}