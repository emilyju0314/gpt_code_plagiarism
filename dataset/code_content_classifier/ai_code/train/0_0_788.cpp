#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, I;
    cin >> n >> I;

    vector<int> sound(n);
    for (int i = 0; i < n; i++) {
        cin >> sound[i];
    }

    sort(sound.begin(), sound.end());

    int k = 8 * I / n;
    k = min(k, 20); // To prevent k from exceeding 20

    int distinct = 1;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (sound[i] != sound[i - 1]) {
            distinct++;
        }
    }

    int l = 0, r = 0;
    int max_distinct = 1;

    for (int i = 0; i < n; i++) {
        while (r < n && (r - l) * k <= I * 8) {
            max_distinct = max(max_distinct, distinct);
            if (r < n && sound[r] == sound[l]) {
                r++;
            } else {
                l++;
            }
        }

        ans = min(ans, n - max_distinct);

        if (sound[i] == sound[r]) {
            distinct--;
        }

        if (sound[i] == sound[l]) {
            distinct++;
        }
    }

    cout << ans << endl;

    return 0;
}