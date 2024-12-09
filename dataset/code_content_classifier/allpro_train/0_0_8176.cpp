#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    int max_beauty = 0;

    for (int i = 0; i < n; i++) {
        int gcd = a[i];
        int beauty = 0;

        for (int j = 0; j < m; j++) {
            while (gcd % b[j] == 0) {
                gcd /= b[j];
                beauty++;
            }
        }

        if (gcd > 1) {
            beauty++;
        }

        max_beauty = max(max_beauty, beauty);
    }

    cout << -max_beauty << endl;

    return 0;
}