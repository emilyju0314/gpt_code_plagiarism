#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> dishes(n);
        vector<int> fish(n), meat(n);
        
        for(int i = 0; i < n; i++) {
            cin >> dishes[i].first >> dishes[i].second;
            fish[i] = dishes[i].first;
            meat[i] = dishes[i].second;
        }

        sort(fish.begin(), fish.end());
        sort(meat.begin(), meat.end());

        long long min_diff = LLONG_MAX;
        long long total_fish = 0, total_meat = 0;

        for(int i = 0; i < n; i++) {
            total_fish += dishes[i].first;
            total_meat += dishes[i].second;
        }

        long long base = abs(total_fish - total_meat);

        for(int i = 0; i <= m; i++) {
            int f1 = lower_bound(fish.begin(), fish.end(), i) - fish.begin();
            int f2 = n - f1;

            int m2 = lower_bound(meat.begin(), meat.end(), m - i) - meat.begin();
            int m1 = n - m2;

            long long diff = 0;

            if(f1 > 0) diff += f1 * i - accumulate(fish.begin(), fish.begin() + f1, 0);
            if(f2 > 0) diff += accumulate(fish.begin() + f1, fish.end(), 0) - f2 * i;

            if(m1 > 0) diff += m1 * (m - i) - accumulate(meat.begin(), meat.begin() + m1, 0);
            if(m2 > 0) diff += accumulate(meat.begin() + m1, meat.end(), 0) - m2 * (m - i);

            if(total_fish >=  m + i && total_meat >= m + m - i) {
                if(base - diff < min_diff) {
                    min_diff = base - diff;
                }
            }
        }

        cout << min_diff << endl;

        for(int i = 0; i < n; i++) {
            int x = min(m, dishes[i].first);
            cout << x << " " << m - x << endl;
        }
    }

    return 0;
}