#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        string names;
        cin >> names;

        unordered_map<char, int> count;
        for (char c : names) {
            count[c]++;
        }

        vector<int> nameCounts;
        for (auto& entry : count) {
            nameCounts.push_back(entry.second);
        }

        int total = n * m;
        int ans = 0;
        for (int i = 0; i < nameCounts.size(); i++) {
            for (int j = i + 1; j < nameCounts.size(); j++) {
                ans += nameCounts[i] * nameCounts[j];
            }
        }

        cout << ans << endl;
    }

    return 0;
}