#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a, b, c, d;
    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (n == 4) {
        cout << -1 << endl;
    } else if (k < n + 2 || k < 2 * n - 1) {
        cout << -1 << endl;
    } else {
        vector<int> path1, path2;

        path1.push_back(a);
        path1.push_back(c);

        for (int i = 1; i <= n; i++) {
            if (i != a && i != b && i != c && i != d) {
                path1.push_back(i);
            }
        }

        path1.push_back(d);
        path1.push_back(b);

        path2.push_back(c);
        path2.push_back(a);

        for (int i = 1; i <= n; i++) {
            if (i != a && i != b && i != c && i != d) {
                path2.push_back(i);
            }
        }

        path2.push_back(b);
        path2.push_back(d);

        for (int i = 0; i < n; i++) {
            cout << path1[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << path2[i] << " ";
        }
        cout << endl;
    }

    return 0;
}