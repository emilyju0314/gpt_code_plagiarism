#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    s--; t--;

    int cnt = 0;
    while (s != t) {
        s = p[s] - 1;
        cnt++;

        if (cnt > n) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;

    return 0;
}