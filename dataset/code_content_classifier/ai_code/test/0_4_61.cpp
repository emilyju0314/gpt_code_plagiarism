#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<int, int> topic_count, difficulty_count;
        vector<pair<int, int>> problems;

        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            problems.push_back({a, b});
            topic_count[a]++;
            difficulty_count[b]++;
        }

        long long ans = 0;

        for(auto& p : problems) {
            ans += max(0, topic_count[p.first] - 1) * max(0, difficulty_count[p.second] - 1);
        }

        cout << ans << endl;
    }

    return 0;
}