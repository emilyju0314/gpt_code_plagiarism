#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<string> answers(n);
        for (int i = 0; i < n; i++) {
            cin >> answers[i];
        }

        vector<int> p(m);
        iota(p.begin(), p.end(), 1); // Fill p with numbers from 1 to m
        sort(p.begin(), p.end(), [&](int a, int b) {
            return x[a - 1] > x[b - 1];
        });

        for (int i = 0; i < m; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}