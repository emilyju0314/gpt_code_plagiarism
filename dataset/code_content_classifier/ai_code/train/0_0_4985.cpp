#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    sort(strengths.begin(), strengths.end());

    for (int i = 0; i < k; i++) {
        vector<int> new_strengths = strengths;
        for (int j = 0; j < n; j += 2) {
            new_strengths[j] ^= x;
        }
        strengths = new_strengths;
    }

    int max_strength = *max_element(strengths.begin(), strengths.end());
    int min_strength = *min_element(strengths.begin(), strengths.end());

    cout << max_strength << " " << min_strength;

    return 0;
}