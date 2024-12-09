#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> problems(n);
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            problems[j] = {a, b};
        }

        unordered_map<int, int> topicCount, difficultyCount;
        for (auto& prob : problems) {
            topicCount[prob.first]++;
            difficultyCount[prob.second]++;
        }

        long long ans = 0;
        for (auto& prob : problems) {
            ans += (topicCount[prob.first] - 1) * (difficultyCount[prob.second] - 1);
        }

        cout << ans << endl;
    }

    return 0;
}