#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> chains(n);
    for (int i = 0; i < n; i++) {
        cin >> chains[i];
    }

    vector<int> ends(n, 0);
    for (int i = 0; i < n; i++) {
        ends[i] = chains[i] - 2;
    }

    sort(ends.begin(), ends.end(), greater<int>());

    long long int ans = 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (ends[i] > 0 && ends[i] < k - sum) {
            ans += ends[i] + 2;
            sum += ends[i];
        } else if (sum < k - 1) {
            ans += k - 1 - sum;
            break;
        }
    }

    if (sum < k - 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}