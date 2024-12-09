#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to determine the winner of the game
string determineWinner(int N, vector<vector<int>>& adjList) {
    queue<int> q;
    vector<int> color(N+1, 0); // 0 -> not painted yet, 1 -> white, 2 -> black
    vector<int> whiteAdjacent(N+1, 0);

    q.push(1); // Starting from vertex 1

    // BFS traversal to assign initial colors to vertices
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int next : adjList[curr]) {
            if(color[next] == 0) {
                color[next] = 3 - color[curr]; // Painting opposite color
                q.push(next);
            }
        }
    }

    // Find white adjacent vertices count for each vertex
    for(int i = 1; i <= N; i++) {
        for(int next : adjList[i]) {
            if(color[next] == 2) whiteAdjacent[i]++;
        }
    }

    // Determining the winner of the game
    if(whiteAdjacent[1] < 1) return "Second";
    if(N % 2 == 1) return "First";

    return "Second";
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adjList(N+1);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    string winner = determineWinner(N, adjList);
    cout << winner << endl;

    return 0;
}