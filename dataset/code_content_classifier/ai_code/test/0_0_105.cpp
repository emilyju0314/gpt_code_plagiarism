#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> variety_values(n, 0);
        vector<vector<pair<int, int>>> food_types(n);

        for (int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;
            int x = min(a, m);
            int y = m - x;

            variety_values[i] = a + b - m;
            food_types[i] = {{x, y}};
        }

        cout << *min_element(variety_values.begin(), variety_values.end()) << endl;
        for (int i = 0; i < n; i++) {
            cout << food_types[i][0].first << " " << food_types[i][0].second << endl;
        }
    }

    return 0;
}