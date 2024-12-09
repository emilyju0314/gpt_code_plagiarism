#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            int count = 0;

            if (freq.count(sum)) {
                count = freq[sum];
            }

            ans = max(ans, count);
        }
    }

    cout << ans;

    return 0;
}