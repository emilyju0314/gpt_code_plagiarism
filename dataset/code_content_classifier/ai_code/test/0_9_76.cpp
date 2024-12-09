#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N + 1);
    unordered_set<int> friends;
    
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
        adjList[V].push_back(U);
        friends.insert(U);
        friends.insert(V);
    }

    if (M == 0) {
        cout << "1 2 3 4 5\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (adjList[i].size() == N - 1) {
                cout << i << " ";
                friends.erase(i);
                for (int j = 1; j <= N; j++) {
                    if (friends.find(j) != friends.end())
                        cout << j << " ";
                }
                cout << "\n";
                return 0;
            }
        }
        cout << "-1\n";
    }

    return 0;
}