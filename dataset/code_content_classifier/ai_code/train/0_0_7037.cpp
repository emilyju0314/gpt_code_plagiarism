#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> friends(n+1);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        friends[v].insert(u);
        friends[u].insert(v);
    }

    long long count = 0;
    for (int i = 1; i <= n; i++) {
        unordered_set<int> mutualFriends;
        for (int friend : friends[i]) {
            for (int friendOfFriend : friends[friend]) {
                if (friendOfFriend != i && friends[friendOfFriend].count(i) == 0) {
                    mutualFriends.insert(friendOfFriend);
                }
            }
        }
        count += mutualFriends.size();
    }

    cout << count << endl;

    return 0;
}