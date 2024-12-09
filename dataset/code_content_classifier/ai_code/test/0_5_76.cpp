#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> friends(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].insert(v);
        friends[v].insert(u);
    }

    for (int i = 1; i <= N; i++) {
        if (friends[i].size() >= 4) {
            cout << i << " ";
            for (int friend : friends[i]) {
                cout << friend << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}