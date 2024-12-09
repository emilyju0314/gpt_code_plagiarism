#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    set<int> possibleSums;
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum += weights[j];
            }
        }

        possibleSums.insert(sum);
    }

    int maxWeights = 0;
    for(int k = 1; k <= n; k++) {
        for(auto sum : possibleSums) {
            vector<int> subsetWeights;
            for(int i = 0; i < n; i++) {
                if((sum & (1 << i)) != 0) {
                    subsetWeights.push_back(weights[i]);
                }
            }

            if(subsetWeights.size() == k) {
                sort(subsetWeights.begin(), subsetWeights.end());
                bool possible = true;
                for(int i = 1; i < k; i++) {
                    if(subsetWeights[i] == subsetWeights[i-1]) {
                        possible = false;
                        break;
                    }
                }

                if(possible) {
                    maxWeights = max(maxWeights, k);
                }
            }
        }
    }

    cout << maxWeights << endl;

    return 0;
}