#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    
    vector<vector<int>> graph(N+1); // adjacency list representation of the tree
    for(int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    cin >> K;
    vector<int> values(N+1, -1); // array to store the values of the vertices
    for(int i = 0; i < K; i++) {
        int V, P;
        cin >> V >> P;
        values[V] = P;
    }
    
    queue<int> q;
    q.push(1); // start with the root of the tree
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nei : graph[cur]) {
            if(values[nei] == -1) {
                values[nei] = values[cur] + 1; // set the value of the neighbor vertex
                q.push(nei);
            } else if(abs(values[nei] - values[cur]) != 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yes" << endl;
    for(int i = 1; i <= N; i++) {
        cout << values[i] << endl;
    }

    return 0;
}