#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    map<int, int> special_offers;
    for (int j = 0; j < m; j++) {
        int d, t;
        cin >> d >> t;
        if (special_offers.find(d) != special_offers.end()) {
            special_offers[d] = min(special_offers[d], k[t-1]);
        } else {
            special_offers[d] = k[t-1];
        }
    }

    int total_days = 0;
    int total_ordered = 0;
    for (int i = 0; i < n; i++) {
        total_ordered += k[i];
    }

    int day = 1;
    while (total_ordered > 0) {
        if (special_offers.find(day) != special_offers.end()) {
            int offer_count = special_offers[day];
            int to_order = min(offer_count, total_ordered);
            total_ordered -= to_order;
            total_days += to_order;
        } else {
            total_ordered -= min(2, total_ordered);
            total_days += 2;
        }
        day++;
    }

    cout << total_days << endl;

    return 0;
}