#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;

    vector<pair<int, int>> days(n);
    vector<int> increase(n);

    for (int i = 0; i < n; i++) {
        int ki, li;
        cin >> ki >> li;
        days[i] = make_pair(ki, li);
        increase[i] = min(ki, li) - min(ki / 2, li);
    }

    sort(increase.rbegin(), increase.rend());

    long long total_sold = 0;
    for (int i = 0; i < n; i++) {
        if (i < f) {
            total_sold += min(days[i].first, days[i].second);
        } else {
            total_sold += min(days[i].first, days[i].second) - min(days[i].first / 2, days[i].second);
        }
    }

    cout << total_sold << endl;

    return 0;
}