#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> monsters(n);
        for (int i = 0; i < n; i++) {
            cin >> monsters[i].first >> monsters[i].second;
        }

        long long total_bullets = 0;
        long long min_health = monsters[0].first;

        for (int i = 1; i < n; i++) {
            min_health = min(monsters[i].second, min_health);
            total_bullets += min_health;
            min_health = min(monsters[i].first, min_health);
        }

        cout << total_bullets << endl;
    }

    return 0;
}