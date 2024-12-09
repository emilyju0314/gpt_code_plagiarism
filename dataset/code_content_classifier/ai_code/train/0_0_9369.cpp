#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    long long ans = 1e18;
    long long prefix_sum = 0;
    long long suffix_sum = 0;

    for (int i = 0; i < n; i++) {
        suffix_sum += weights[i];
    }

    for (int i = 1; i < n; i++) {
        prefix_sum += weights[i-1];
        suffix_sum -= weights[i-1];

        ans = min(ans, max((long long)weights[i], prefix_sum + suffix_sum));
    }

    cout << ans << endl;

    return 0;
}