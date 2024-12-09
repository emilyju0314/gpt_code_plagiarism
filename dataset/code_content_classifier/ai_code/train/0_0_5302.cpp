#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, vector<int>> friends;
    vector<int> personalTokens(n, 1);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        personalTokens[a-1] += 2;
        personalTokens[b-1] += 2;
    }

    vector<int> keptPersonalTokens;
    vector<pair<pair<int, int>, int>> friendshipTokens;

    for (int i = 0; i < n; i++) {
        int tokens = personalTokens[i];
        if (tokens != friends[i+1].size() * 2) {
            keptPersonalTokens.push_back(i+1);
        }
        for (int friend : friends[i+1]) {
            friendshipTokens.push_back({{i+1, friend}, min(tokens/2, 2)});
            tokens -= min(tokens/2, 2);
        }
    }

    cout << keptPersonalTokens.size() << endl;
    for (int token : keptPersonalTokens) {
        cout << token << " ";
    }
    cout << endl;

    for (auto ft : friendshipTokens) {
        cout << ft.first.first << " " << ft.first.second << " " << ft.second << endl;
    }

    return 0;
}