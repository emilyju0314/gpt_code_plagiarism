#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> degrees(n);
    for (int i = 0; i < n; i++) {
        cin >> degrees[i];
    }
    
    int dn = degrees[n-1] + 1;
    
    vector<pair<int, int>> edges;
    
    for (int i = 1; i < dn; i++) {
        for (int j = 1; j < degrees.size(); j++) {
            edges.push_back({i, i+j});
            edges.push_back({i+j, i});
        }
    }
    
    cout << edges.size() << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    return 0;
}