#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> weights(n);
        map<int, int> weightCount;

        for (int j = 0; j < n; j++) {
            cin >> weights[j];
            weightCount[weights[j]]++;
        }

        int maxTeams = 0;

        for (int s = 2; s <= 2*n; s++) {
            int pairs = 0;
            for (auto it = weightCount.begin(); it != weightCount.end(); ++it) {
                int weight = it->first;
                int oppositeWeight = s - weight;

                if (weightCount.find(oppositeWeight) == weightCount.end()) {
                    continue;
                }

                int pairsWithWeight = min(it->second, weightCount[oppositeWeight]);
                pairs += pairsWithWeight;
            }

            maxTeams = max(maxTeams, pairs / 2);
        }

        cout << maxTeams << endl;
    }

    return 0;
}