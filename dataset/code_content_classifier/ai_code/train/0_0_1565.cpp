#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> topics(n);
    for (int i = 0; i < n; i++) {
        cin >> topics[i];
    }

    map<int, int> topicFrequency;
    for (int i = 0; i < n; i++) {
        topicFrequency[topics[i]]++;
    }

    int maxProblems = 0;
    for (auto it = topicFrequency.begin(); it != topicFrequency.end(); it++) {
        int cnt = it->second;
        int currentTopics = cnt;

        for (int i = 2; i <= cnt; i *= 2) {
            currentTopics += cnt / i * i;
        }

        maxProblems = max(maxProblems, currentTopics);
    }

    cout << maxProblems << endl;

    return 0;
}