#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> contrast(n);
    for(int i = 0; i < n; i++) {
        cin >> contrast[i];
    }

    sort(contrast.begin(), contrast.end());

    int ans = contrast[n-1] - contrast[0];
    vector<int> diffs;
    for(int i = 1; i < n; i++) {
        diffs.push_back(contrast[i] - contrast[i-1]);
    }

    sort(diffs.begin(), diffs.end(), greater<int>());

    for(int i = 0; i < k-1; i++) {
        if(i < diffs.size()) {
            ans -= diffs[i];
        }
    }

    cout << ans << endl;

    return 0;
}