#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_set<int> unique_nums;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            unique_nums.insert(a[i]);
        }

        vector<pair<int, int>> pairs;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if (unique_nums.find(a[i]%a[j]) == unique_nums.end() && unique_nums.find(a[j]%a[i]) == unique_nums.end()) {
                    pairs.push_back({a[i], a[j]});
                }
            }
        }

        for (int i = 0; i < n/2; i++) {
            cout << pairs[i].first << " " << pairs[i].second << endl;
        }
    }

    return 0;
}