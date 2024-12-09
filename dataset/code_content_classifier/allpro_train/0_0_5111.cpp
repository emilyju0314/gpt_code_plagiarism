#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    map<int, long long> counter;
    map<int, long long> prefix_sum;

    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < n; i++) {
        int a = pairs[i].first;
        int b = pairs[i].second;

        long long cost = 0;
        if (counter.count(a)) {
            cost = counter[a];
        }

        if (prefix_sum.count(a)) {
            cost += prefix_sum[a];
        }

        cout << cost << endl;

        if (counter.count(a + 1)) {
            counter[a + 1] += b;
        } else {
            counter[a + 1] = b;
        }

        if (prefix_sum.count(a + 1)) {
            prefix_sum[a + 1] += b * (a + 1);
        } else {
            prefix_sum[a + 1] = b * (a + 1);
        }
    }

    return 0;
}