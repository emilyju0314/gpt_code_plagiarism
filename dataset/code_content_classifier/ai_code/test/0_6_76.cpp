#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> adjList(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    if (M == 0) {
        cout << "1 2 3 4 5" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (adjList[i].size() + 1 >= 5) {
            set<int> invited;
            invited.insert(i);
            for (int friend : adjList[i]) {
                if (invited.size() == 5) {
                    for (int person : invited) {
                        cout << person << " ";
                    }
                    cout << endl;
                    return 0;
                }
                invited.insert(friend);
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}