#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> Yes(N), No(N);
    
    for (int i = 1; i < N; i++) {
        cin >> Yes[i] >> No[i];
    }
    
    vector<int> visited(N, 0);
    visited[1] = 1;
    
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    int shortestTime = 0;
    bool allEndingsReached = false;
    
    while (!q.empty()) {
        int currentPos = q.front().first;
        int currentTime = q.front().second;
        q.pop();
        
        // Check if the current position leads to an ending
        if (Yes[currentPos] == N && No[currentPos] == N) {
            shortestTime = max(shortestTime, currentTime);
        }
        
        // Check if the two possible choices have been visited
        if (visited[Yes[currentPos]] == 0) {
            q.push({Yes[currentPos], currentTime + 1});
            visited[Yes[currentPos]] = 1;
        }
        
        if (visited[No[currentPos]] == 0) {
            q.push({No[currentPos], currentTime + 1});
            visited[No[currentPos]] = 1;
        }
        
        // Check if all endings have been reached
        if (visited[N]) {
            allEndingsReached = true;
            break;
        }
    }
    
    cout << shortestTime * 2 << endl;
    
    return 0;
}