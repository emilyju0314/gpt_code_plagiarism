#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    vector<long long> prefixsum(n+1);
    unordered_set<int> destroyed;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        destroyed.insert(order[i]);
        total += arr[order[i]-1];
        
        auto it = destroyed.lower_bound(order[i]);
        if (it != destroyed.begin()) {
            auto prev_it = prev(it);
            prefixsum[order[i]] = prefixsum[*prev_it];
        }

        cout << total - prefixsum[order[i]] << endl;
        prefixsum[order[i]+1] = total;
    }

    return 0;
}