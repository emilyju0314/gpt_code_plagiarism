#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> topic_count, difficulty_count, topic_difficulty_count;
        vector<pair<int, int>> problems(n);

        for (int i = 0; i < n; i++) {
            cin >> problems[i].first >> problems[i].second;
            topic_count[problems[i].first]++;
            difficulty_count[problems[i].second]++;
            topic_difficulty_count[{problems[i].first, problems[i].second}]++;
        }

        long long ans = 0;

        for (auto p : problems) {
            ans += (n - topic_count[p.first]) + (n - difficulty_count[p.second]) - (topic_difficulty_count[p]);
        }

        cout << ans / 2 << endl;
    }

    return 0;
}