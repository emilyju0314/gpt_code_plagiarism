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

        vector<pair<int, int>> voters;

        for(int i=0; i<n; i++) {
            int m, p;
            cin >> m >> p;
            voters.push_back(make_pair(m, p));
        }

        sort(voters.begin(), voters.end());

        long long total_coins = 0;
        long long votes_needed = 0;

        for(int i=0; i<n; i++) {
            if(votes_needed < voters[i].first) {
                total_coins += voters[i].second;
                votes_needed++;
            } else {
                votes_needed += voters[i].second;
            }
        }

        cout << total_coins << endl;
    }

    return 0;
}