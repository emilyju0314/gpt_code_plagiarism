#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // Initialize counters for topic and difficulty
        vector<int> topicCount(n+1, 0);
        vector<int> difficultyCount(n+1, 0);

        // Store the topic and difficulty of each problem
        vector<pair<int, int>> problems(n);
        for(int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            problems[i] = make_pair(a, b);
            topicCount[a]++;
            difficultyCount[b]++;
        }

        long long count = 0;
        // Calculate the number of ways to select 3 problems
        for(int i=0; i<n; i++) {
            int a = problems[i].first;
            int b = problems[i].second;
            count += (topicCount[a]-1) * (difficultyCount[b]-1);
        }

        cout << count << endl;
    }

    return 0;
}