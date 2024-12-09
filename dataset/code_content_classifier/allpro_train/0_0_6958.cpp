#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> coupons(m);
    for(int i = 0; i < m; i++) {
        cin >> coupons[i].first >> coupons[i].second;
    }

    sort(coupons.begin(), coupons.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    long long money = 0;
    int remaining = n;
    for(int i = 0; i < m; i++) {
        money += (long long) min(remaining, coupons[i].first) * coupons[i].second;
        remaining -= min(remaining, coupons[i].first);
        if(remaining == 0) {
            break;
        }
    }

    cout << money << endl;

    return 0;
}