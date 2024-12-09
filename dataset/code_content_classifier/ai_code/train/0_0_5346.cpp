#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N + 1);
    vector<int> inDegree(N + 1, 0);
    vector<int> outDegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adjList[A].push_back(B);
        inDegree[B]++;
        outDegree[A]++;
    }

    vector<int> vertices;

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0 && outDegree[i] == 1) {
            vertices.push_back(i);
        }
    }

    if (vertices.size() == 0) {
        cout << "-1" << endl;
    } else {
        cout << vertices.size() << endl;
        for (int v : vertices) {
            cout << v << endl;
        }
    }

    return 0;
}