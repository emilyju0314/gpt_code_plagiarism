#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> computeBrainLatency(int n, vector<int> parent_brain) {
    vector<int> brain_latency(n, 0);
    vector<vector<int>> graph(n);
    for(int i=1; i<n; i++) {
        graph[parent_brain[i-1]].push_back(i);
    }

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : graph[cur]) {
            brain_latency[next] = brain_latency[cur] + 1;
            q.push(next);
        }
    }

    vector<int> result;
    for(int i=1; i<n; i++) {
        result.push_back(brain_latency[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent_brain(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> parent_brain[i];
    }

    vector<int> result = computeBrainLatency(n, parent_brain);

    for(int i=0; i<n-1; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}