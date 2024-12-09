#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<pair<int, int>, int>> vouchers; // store vouchers as pairs of (duration, cost)
    
    for(int i = 0; i < n; i++) {
        int li, ri, costi;
        cin >> li >> ri >> costi;
        vouchers.push_back({{ri - li + 1, costi}, li}); // store duration, cost, and start day of the voucher
    }
    
    sort(vouchers.begin(), vouchers.end()); // sort vouchers by duration

    int min_cost = INT_MAX;
    bool found = false;

    for(int i = 0; i < n; i++) {
        int duration1 = vouchers[i].first.first; // duration of first voucher
        int cost1 = vouchers[i].first.second; // cost of first voucher
        int start_day1 = vouchers[i].second; // start day of first voucher

        // find second voucher with non-overlapping duration and total duration matching x
        auto it = lower_bound(vouchers.begin(), vouchers.end(), make_pair(make_pair(x - duration1, 0), 0));
        
        if(it != vouchers.end() && it->first.first == x - duration1 && it->second > start_day1 + duration1) {
            int cost2 = it->first.second;
            min_cost = min(min_cost, cost1 + cost2);
            found = true;
        }
    }

    if(found) {
        cout << min_cost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}