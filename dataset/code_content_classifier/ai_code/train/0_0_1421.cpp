#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isHamiltonianPath(int n, vector<pair<int, int>> edges) {
    vector<int> nodes(n, 0);
    for(auto edge: edges) {
        nodes[edge.first - 1]++;
        nodes[edge.second - 1]++;
    }
    
    sort(nodes.begin(), nodes.end());
    
    if(nodes[0] != 1 || nodes[n - 1] != n - 1) {
        return false;
    }
    for(int i = 1; i < n - 1; i++) {
        if(nodes[i] != 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int vi, ui;
        cin >> vi >> ui;
        edges.push_back({vi, ui});
    }
    
    if(isHamiltonianPath(n, edges)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}