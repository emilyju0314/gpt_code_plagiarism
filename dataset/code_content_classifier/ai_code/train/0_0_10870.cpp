#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;
    int distinct = 0;
    int l = 0, r = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 0) {
            distinct++;
        }
        freq[a[i]]++;

        while (distinct > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                distinct--;
            }
            l++;
        }

        if (i - l + 1 > maxLength) {
            maxLength = i - l + 1;
            r = i;
        }
    }

    cout << l + 1 << " " << r + 1 << endl;

    return 0;
}