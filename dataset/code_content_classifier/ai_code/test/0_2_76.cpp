#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> friendships(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        friendships[U].push_back(V);
        friendships[V].push_back(U);
    }

    for (int i = 1; i <= N; i++) {
        if (friendships[i].size() >= 4) {
            cout << i << " ";
            for (int j = 1; j <= N; j++) {
                if (j != i && find(friendships[i].begin(), friendships[i].end(), j) == friendships[i].end()) {
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