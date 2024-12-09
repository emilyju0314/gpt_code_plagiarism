#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> findOptimalChocolates(vector<int>& chocolates) {
    int n = chocolates.size();
    pair<int, int> result;
    int maxExchanges = 0;

    for (int i = 0; i < n; i++) {
        int x = chocolates[i];
        int k = 0;
        while ((1 << k) < x) {
            k++;
        }

        int new_type = (1 << k) - x;

        auto it = lower_bound(chocolates.begin(), chocolates.end(), new_type);
        if (it != chocolates.end()) {
            int j = it - chocolates.begin();

            if (i == j) j++;

            int exchanges = k + (chocolates[j] == new_type);

            if (exchanges > maxExchanges) {
                maxExchanges = exchanges;
                result = {i + 1, j + 1};
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    pair<int, int> result = findOptimalChocolates(chocolates);

    cout << result.first << " " << result.second << " " << max(result.first, result.second) - min(result.first, result.second) << endl;

    return 0;
}