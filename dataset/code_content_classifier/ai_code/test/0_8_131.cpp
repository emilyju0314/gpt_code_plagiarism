#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> findMaxMinNumExchanges(vector<int>& chocolates) {
    int n = chocolates.size();
    int min_exchanges = INT_MAX;
    int x, y;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = chocolates[i] ^ chocolates[j];
            int num_exchanges = 0;

            while (target) {
                target >>= 1;
                num_exchanges++;
            }

            if (num_exchanges < min_exchanges) {
                min_exchanges = num_exchanges;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    return make_pair(x, y);
}

int main() {
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    pair<int, int> result = findMaxMinNumExchanges(chocolates);
    cout << result.first << " " << result.second << " " << (1 << (result.first ^ result.second)) - chocolates[result.first-1] << endl;

    return 0;
}