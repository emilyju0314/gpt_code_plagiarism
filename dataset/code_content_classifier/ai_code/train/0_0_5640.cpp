#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    map<long long, vector<int>> adjList;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && (numbers[i] & numbers[j]) != 0) {
                adjList[numbers[i]].push_back(numbers[j]);
            }
        }
    }

    int shortestCycle = -1;
    for(auto& num : numbers) {
        queue<pair<int, int>> q;
        q.push({num, 0});

        map<int, bool> visited;
        while(!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(visited[node]) {
                shortestCycle = (shortestCycle == -1) ? dist : min(shortestCycle, dist);
                break;
            }

            visited[node] = true;

            for(const auto& neighbor : adjList[node]) {
                q.push({neighbor, dist + 1});
            }
        }
    }

    cout << shortestCycle << endl;

    return 0;
}