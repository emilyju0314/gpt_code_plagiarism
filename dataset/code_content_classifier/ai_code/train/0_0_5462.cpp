#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> candies(n);
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> candies[i];
        cnt[candies[i] % k]++;
    }

    int pairs = 0;

    pairs += cnt[0] / 2;
    for (int i = 1; i <= k / 2 && i != k - i; i++) {
        pairs += min(cnt[i], cnt[k - i]);
    }
    
    if (k % 2 == 0) {
        pairs += cnt[k / 2] / 2;
    }

    cout << pairs * 2 << endl;

    return 0;
}