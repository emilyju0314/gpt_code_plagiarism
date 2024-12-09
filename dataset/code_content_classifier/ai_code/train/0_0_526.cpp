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

        vector<pair<int, int>> voters(n);
        for(int i = 0; i < n; i++) {
            cin >> voters[i].first >> voters[i].second;
        }

        sort(voters.begin(), voters.end());

        long long total_cost = 0;
        long long num_voters = 0;
        for(int i = 0; i < n; i++) {
            if (num_voters < voters[i].first) {
                total_cost += (voters[i].first - num_voters) * voters[i].second;
                num_voters = voters[i].first;
            }
            num_voters++;
        }

        cout << total_cost << endl;
    }

    return 0;
}