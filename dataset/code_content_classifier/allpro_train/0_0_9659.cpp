#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, pair<int, int>> count; // key is number, value is pair of starting index and ending index
    for (int i = 0; i < n; i++) {
        if (count.find(arr[i]) == count.end()) {
            count[arr[i]] = make_pair(i, i);
        } else {
            count[arr[i]].second = i;
        }
    }

    pair<int, int> ans = count[arr[0]];
    for (auto p : count) {
        if (p.second.second - p.second.first < ans.second - ans.first) {
            ans = p.second;
        }
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;

    return 0;
}