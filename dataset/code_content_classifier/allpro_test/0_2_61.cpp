#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        unordered_map<int, int> topicCount, difficultyCount;
        
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            topicCount[a]++;
            difficultyCount[b]++;
        }
        
        long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
        
        for (auto& topic : topicCount) {
            ans -= 1LL * topic.second * (topic.second - 1) / 2 * (n - topic.second);
        }
        
        for (auto& difficulty : difficultyCount) {
            ans -= 1LL * difficulty.second * (difficulty.second - 1) / 2 * (n - difficulty.second);
        }
        
        cout << ans << endl;
    }

    return 0;
}