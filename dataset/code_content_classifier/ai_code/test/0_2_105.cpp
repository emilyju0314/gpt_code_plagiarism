#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> dishes;
        vector<int> m(n);
        vector<vector<int>> result(n, vector<int>(2, 0));

        for(int i = 0; i < n; i++) {
            int a, b, dish_m;
            cin >> a >> b >> dish_m;
            dishes.push_back(make_pair(a, b));
            m[i] = dish_m;
        }

        sort(dishes.begin(), dishes.end());

        int dish_idx = 0;
        for(int i = 0; i < n; i++) {
            while(dish_idx < n && dishes[dish_idx].first == i) {
                result[dish_idx][0] = min(dishes[dish_idx].first, m[dish_idx]);
                result[dish_idx][1] = m[dish_idx] - result[dish_idx][0];
                dish_idx++;
            }
        }

        int min_variety = 1;
        cout << min_variety << endl;
        for(int i = 0; i < n; i++) {
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }

    return 0;
}