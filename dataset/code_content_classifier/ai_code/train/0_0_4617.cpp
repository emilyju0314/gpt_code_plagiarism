#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r};
    }

    // Count the frequency of each number in the array
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Iterate through each query and count the numbers that occur exactly x times
    for (int i = 0; i < m; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        
        unordered_map<int, int> count;
        for (int j = l-1; j < r; j++) {
            count[arr[j]]++;
        }
        
        int ans = 0;
        for (auto it : count) {
            if (it.second == it.first) {
                ans++;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}