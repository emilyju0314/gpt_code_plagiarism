#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canReachDestination(int N, int M, int Z, vector<pair<int, int>> sections) {
    vector<vector<int>> adjList(N + 1);
    for (pair<int, int> section : sections) {
        adjList[section.first].push_back(section.second);
        adjList[section.second].push_back(section.first);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(1, Z));

    while (!q.empty()) {
        int currStation = q.front().first;
        int stepsLeft = q.front().second;
        q.pop();

        if (currStation == N && stepsLeft == 0) {
            return true;
        }

        if (stepsLeft > 0) {
            for (int nextStation : adjList[currStation]) {
                q.push(make_pair(nextStation, stepsLeft - 1));
            }
        }
    }

    return false;
}

int main() {
    int N, M, Z;
    while (1) {
        cin >> N >> M >> Z;
        if (N == 0 && M == 0 && Z == 0) {
            break;
        }

        vector<pair<int, int>> sections;
        for (int i = 0; i < M; i++) {
            int s, d;
            cin >> s >> d;
            sections.push_back(make_pair(s, d));
        }

        if (canReachDestination(N, M, Z, sections)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}