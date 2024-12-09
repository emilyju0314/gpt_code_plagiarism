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

        vector<pair<int, int>> problems(n);
        unordered_set<int> topics, difficulties;

        for (int i = 0; i < n; i++) {
            int topic, difficulty;
            cin >> topic >> difficulty;
            problems[i] = make_pair(topic, difficulty);
            topics.insert(topic);
            difficulties.insert(difficulty);
        }

        if (topics.size() == n || difficulties.size() == n) {
            cout << n*(n-1)*(n-2)/6 << endl;
        } else {
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    for (int k = j+1; k < n; k++) {
                        if (problems[i].first != problems[j].first &&
                            problems[i].first != problems[k].first &&
                            problems[j].first != problems[k].first &&
                            problems[i].second != problems[j].second &&
                            problems[i].second != problems[k].second &&
                            problems[j].second != problems[k].second) {
                            count++;
                        }
                    }
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}