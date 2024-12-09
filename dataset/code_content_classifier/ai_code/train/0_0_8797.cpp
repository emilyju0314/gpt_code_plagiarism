#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prep_costs(n);
    vector<int> print_costs(n);

    for(int i = 0; i < n; i++) {
        cin >> prep_costs[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> print_costs[i];
    }

    vector<int> min_prep(n, INT_MAX);
    vector<int> dp(n+1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = min(i, k); j >= 1; j--) {
            dp[j] = min(dp[j] + prep_costs[i], min_prep[i] + print_costs[i]);
            min_prep[i+1] = min(min_prep[i+1], dp[j]);
        }
    }

    cout << min_prep[n] << endl;

    return 0;
}