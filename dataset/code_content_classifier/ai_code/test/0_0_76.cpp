#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isFriend(vector<unordered_set<int>>& friends, int i, int j) {
    return friends[i].find(j) != friends[i].end();
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<unordered_set<int>> friends(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].insert(v);
        friends[v].insert(u);
    }

    for (int i = 1; i <= N; i++) {
        if (friends[i].size() >= 4) {
            cout << i << " ";
            for (int j = 1; j <= N; j++) {
                if (i != j && !isFriend(friends, i, j)) {
                    cout << j << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}