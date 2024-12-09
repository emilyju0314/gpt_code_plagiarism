#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> houses(n);
        for (int i = 0; i < n; i++) {
            cin >> houses[i];
        }

        vector<int> generators(k);
        int prev = 0;
        int next = n - k;
        for (int i = 0; i < k; i++) {
            generators[i] = houses[prev + next / 2];
            prev += next / 2;
            next = n - prev - (k - i - 1);
        }

        sort(generators.begin(), generators.end());

        long long total_length = 0;
        int g = 0;

        for (int i = 0; i < n; i++) {
            total_length += abs(generators[g] - houses[i]);
            if (g + 1 < k && abs(generators[g + 1] - houses[i]) < abs(generators[g] - houses[i])) {
                g++;
                total_length -= abs(generators[g] - houses[i]);
            }
        }

        cout << total_length << endl;
    }

    return 0;
}