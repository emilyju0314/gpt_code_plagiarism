#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> problems(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            problems[i] = {a, b};
        }

        sort(problems.begin(), problems.end());

        long long count = 0;

        int topic_count = min(3, n);
        int difficulty_count = min(3, n);

        count += 1LL * topic_count * (topic_count - 1) * (topic_count - 2) / 6;
        count += 1LL * difficulty_count * (difficulty_count - 1) * (difficulty_count - 2) / 6;

        int same_topic = 1;
        int same_difficulty = 1;

        for (int i = 1; i < n; i++) {
            if (problems[i].first == problems[i-1].first) {
                same_topic++;
            } else {
                count -= 1LL * same_topic * (same_topic - 1) * (same_topic - 2) / 6;
                same_topic = 1;
            }

            if (problems[i].second == problems[i-1].second) {
                same_difficulty++;
            } else {
                count -= 1LL * same_difficulty * (same_difficulty - 1) * (same_difficulty - 2) / 6;
                same_difficulty = 1;
            }
        }

        count -= 1LL * same_topic * (same_topic - 1) * (same_topic - 2) / 6;
        count -= 1LL * same_difficulty * (same_difficulty - 1) * (same_difficulty - 2) / 6;

        cout << count << endl;
    }

    return 0;
}