#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> dishes(n);
        vector<int> balance(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            dishes[i] = make_pair(a, b);
            balance[i] = a - b;
        }

        int min_balance = 0;
        for (int i = 0; i < n; i++) {
            min_balance += abs(balance[i]);
        }

        min_balance /= 2;

        cout << min_balance << endl;

        for (int i = 0; i < n; i++) {
            int fish = min(dishes[i].first, m);
            int meat = m - fish;
            cout << fish << " " << meat << endl;
        }
    }

    return 0;
}