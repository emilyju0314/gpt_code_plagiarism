#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;
    
    vector<int> scores(m);
    for(int i = 0; i < m; i++) {
        cin >> scores[i];
    }
    
    vector<int> vertices;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < scores[i]; j++) {
            vertices.push_back(i);
        }
    }
    
    int n = vertices.size();
    
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(vertices[i] < vertices[j]) {
                graph[i][j] = 1;
            } else {
                graph[j][i] = 1;
            }
        }
    }
    
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    
    return 0;
}