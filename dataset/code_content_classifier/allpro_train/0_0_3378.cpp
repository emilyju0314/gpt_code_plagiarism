#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> voters;
    
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        voters.push_back({p, c});
    }

    int total = 0;
    int bytecoins = 0;

    for (int i = 1; i <= m; i++) {
        if (i == 1) continue;

        vector<int> costs;
        for (auto voter : voters) {
            if (voter.first == i) {
                costs.push_back(voter.second);
            }
        }

        sort(costs.begin(), costs.end());

        int count = 0;
        for (int j = 0; j < costs.size(); j++) {
            if (total + count < j + 1) {
                bytecoins += costs[j];
                count++;
            }
        }

        total += count;
    }

    cout << bytecoins << endl;

    return 0;
}