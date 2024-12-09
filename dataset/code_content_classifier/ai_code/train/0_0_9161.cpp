#include <iostream>
#include <vector>
using namespace std;

vector<int> winningVertices;

void dfs(int curr, int parent, vector<vector<int>>& adjList, vector<int>& stones) {
    int totalStones = stones[curr];
    for(int neighbor : adjList[curr]) {
        if(neighbor == parent) {
            continue;
        }
        totalStones += stones[neighbor];
        dfs(neighbor, curr, adjList, stones);
    }
    if(totalStones % 2 == 0) {
        winningVertices.push_back(curr);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> stones(N);
    for(int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    vector<vector<int>> adjList(N);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(0, -1, adjList, stones);

    for(int v : winningVertices) {
        cout << v+1 << " ";
    }
    cout << endl;

    return 0;
}