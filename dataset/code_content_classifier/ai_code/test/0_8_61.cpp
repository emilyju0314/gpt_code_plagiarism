#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int, int> topicCount;
        map<int, int> difficultyCount;
        long long totalWays = 0;

        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            topicCount[a]++;
            difficultyCount[b]++;
        }

        for(auto it = topicCount.begin(); it != topicCount.end(); it++) {
            int count = it->second;
            totalWays += (count * (count - 1) / 2);
        }

        for(auto it = difficultyCount.begin(); it != difficultyCount.end(); it++) {
            int count = it->second;
            totalWays += (count * (count - 1) / 2);
        }

        cout << totalWays << endl;
    }

    return 0;
}