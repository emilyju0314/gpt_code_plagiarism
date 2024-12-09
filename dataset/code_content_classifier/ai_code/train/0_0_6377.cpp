#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<vector<int>> adj;
vector<int> cnt;
unordered_map<char, int> letterCount;

int dfs(int node) {
    int maxCount = 0;
    for(int neighbor : adj[node]) {
        maxCount = max(maxCount, dfs(neighbor));
    }
    int currentLetterCount = ++letterCount[s[node]];
    cnt[node] = currentLetterCount;
    return max(maxCount, currentLetterCount);
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    cnt.resize(n);

    cin >> s;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
    }

    int maxValue = 0;

    for(int i = 0; i < n; i++) {
        if(cnt[i] == 0) {
            letterCount.clear();
            maxValue = max(maxValue, dfs(i));
        }
    }

    int result = maxValue;
    for(int i = 0; i < n; i++) {
        if(cnt[i] == maxValue && letterCount[s[i]] == maxValue) {
            result = -1;
            break;
        }
    }

    cout << result << endl;

    return 0;
}