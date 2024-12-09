#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    sort(prices.rbegin(), prices.rend());

    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += prices[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < min(M, N-i); j++) {
            prices[i] /= 2;
        }
    }

    long long discounted_cost = 0;
    for (int i = 0; i < N; i++) {
        discounted_cost += prices[i];
    }

    cout << discounted_cost << endl;

    return 0;
}