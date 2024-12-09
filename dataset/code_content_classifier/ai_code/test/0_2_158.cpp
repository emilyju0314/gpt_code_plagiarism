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
        for (int i = 0; i < m; i++) {
            p[i] = i + 1;
        }

        sort(p.begin(), p.end()); // Sorting to get a permutation

        cout << " ";
        for (int i = 0; i < m; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}