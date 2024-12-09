#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> adjList(N);
    for (int i = 1; i < N; i++) {
        int parent;
        cin >> parent;
        adjList[parent-1].push_back(i);
    }

    vector<int> subtreeFruits(N, 0);
    vector<int> subtreeDistances(N, 0);

    for (int day = 0; day < Q; day++) {
        int X;
        cin >> X;
        X--;

        queue<int> q;
        q.push(X);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            subtreeFruits[curr] += A[curr];
            subtreeDistances[curr] = 0;

            for (int child : adjList[curr]) {
                q.push(child);
                subtreeFruits[child] = subtreeFruits[curr];
                subtreeDistances[child] = subtreeDistances[curr] + 1;
            }
        }

        int totalDistance = 0;
        int numHarvested = 0;

        for (int i = 0; i < N; i++) {
            if (subtreeFruits[i] > 0) {
                numHarvested++;
                totalDistance += subtreeDistances[i];
                subtreeFruits[i] = 0;
                subtreeDistances[i] = 0;
            }
        }

        cout << totalDistance << " " << numHarvested << endl;
    }

    return 0;
}