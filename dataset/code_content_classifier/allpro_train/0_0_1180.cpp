#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

vector<double> calculateProbabilities(int n, int k, vector<double>& p) {
    vector<double> probabilities(n, 0.0);

    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;

        vector<int> cache(n, 0);
        map<int, int> lastQuery;

        for (int query = 0; query <= 100; query++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cache[i]++;
                    lastQuery[i] = query;
                }
            }

            if (query == 100) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        probabilities[i] += p[i];
                    }
                }
            }

            if (cache.size() > k) {
                int lru = -1;
                int lruTime = INT_MAX;
                for (int i = 0; i < n; i++) {
                    if (lastQuery.count(i) && lastQuery[i] < lruTime) {
                        lru = i;
                        lruTime = lastQuery[i];
                    }
                }

                cache[lru] = 0;
                lastQuery.erase(lru);
            }
        }
    }

    return probabilities;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<double> probabilities = calculateProbabilities(n, k, p);

    for (double probability : probabilities) {
        cout << fixed << setprecision(15) << probability << " ";
    }

    cout << endl;

    return 0;
}