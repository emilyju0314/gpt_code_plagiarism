#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<char> state(V);
    for(int i = 0; i < V; i++) {
        cin >> state[i];
    }

    vector<vector<int>> adjList(V);
    for(int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        adjList[s].push_back(t);
        adjList[t].push_back(s);
    }

    string result = "";
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(state[i] == '?') {
            q.push(i);
            break;
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        char nextLetter = 'a';
        for(int neighbor : adjList[curr]) {
            if(state[neighbor] == nextLetter) {
                nextLetter++;
            }
        }

        state[curr] = nextLetter;
        result += nextLetter;

        for(int neighbor : adjList[curr]) {
            if(state[neighbor] == '?') {
                q.push(neighbor);
            }
        }
    }

    cout << result << endl;

    return 0;
}