#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> vertices(n);
        for (int i = 0; i < n - 2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            vertices[a - 1]++;
            vertices[b - 1]++;
            vertices[c - 1]++;
        }

        int start = -1;
        for (int i = 0; i < n; i++) {
            if (vertices[i] == 1) {
                start = i;
                break;
            }
        }

        vector<int> p(n), q(n - 2);
        int current = start, next;
        for (int i = 0; i < n; i++) {
            p[i] = current + 1;
            for (int j = 0; j < n - 2; j++) {
                if ((i < n - 2 && (current + 1 == a || current + 1 == b || current + 1 == c))
                    || (i >= n - 2 && (current + 1 != a && current + 1 != b && current + 1 != c))) {
                    q[i] = j;
                    next = a + b + c - current - start - 1;
                    break;
                }
            }
            current = next;
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n - 2; i++) {
            cout << q[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}