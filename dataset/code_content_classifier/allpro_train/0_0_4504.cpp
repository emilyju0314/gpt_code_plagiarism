#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> partition1, partition2;
    
    vector<vector<int>> adj(n, vector<int>(n, 0));
    
    // Helper function to count edges between two sets of vertices
    auto count_edges = [&](vector<int>& s) {
        int m = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                m += adj[s[i]][s[j]];
            }
        }
        return m;
    };
    
    // Helper function to check if a cycle exists
    auto check_cycle = [&](vector<int> cycle) {
        for (int i = 0; i < cycle.size(); i++) {
            for (int j = i + 1; j < cycle.size(); j++) {
                if (adj[cycle[i]][cycle[j]]) {
                    cout << "N " << j - i + 1 << endl;
                    for (int k = i; k <= j; k++) {
                        cout << cycle[k] + 1 << " ";
                    }
                    cout << endl;
                    return true;
                }
            }
        }
        return false;
    };
    
    // Initialize set of all vertices
    set<int> remaining;
    for (int i = 0; i < n; i++) {
        remaining.insert(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << "? " << n << endl;
        for (int j = 0; j < n; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
        int m;
        cin >> m;
        
        if (m == -1) {
            return 0;
        }
        
        adj[i][i] = m;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                adj[i][j] = m;
                adj[j][i] = m;
            }
        }
    }
    
    while (!remaining.empty()) {
        int s = min(2, (int)remaining.size());
        
        cout << "? " << s << endl;
        for (int vertex : partition1) {
            cout << vertex + 1 << " ";
        }
        for (int vertex : partition2) {
            cout << vertex + 1 << " ";
        }
        cout << endl;
        int m;
        cin >> m;
        
        if (m == -1) {
            return 0;
        }
        
        if (m == 0) {
            set<int> tmp;
            for (int vertex : remaining) {
                tmp.insert(vertex);
            }
            for (int vertex : partition1) {
                tmp.erase(vertex);
            }
            for (int vertex : partition2) {
                tmp.erase(vertex);
            }
            
            partition1.insert(partition1.end(), tmp.begin(), tmp.end());
            break;
        } else if (m == n - partition1.size() || m == n - partition2.size()) {
            set<int> tmp;
            for (int vertex : remaining) {
                tmp.insert(vertex);
            }
            for (int vertex : partition1) {
                tmp.erase(vertex);
            }
            for (int vertex : partition2) {
                tmp.erase(vertex);
            }
            
            if (m == n - partition1.size()) {
                partition1.insert(partition1.end(), tmp.begin(), tmp.end());
            } else {
                partition2.insert(partition2.end(), tmp.begin(), tmp.end());
            }
            break;
        } else {
            vector<int> vertices_in_s;
            for (int vertex : partition1) {
                vertices_in_s.push_back(vertex);
            }
            for (int vertex : partition2) {
                vertices_in_s.push_back(vertex);
            }
            
            if (count_edges(partition1) == 0 && !check_cycle(vertices_in_s)) {
                return 0;
            }
            
            if (count_edges(partition2) == 0 && !check_cycle(vertices_in_s)) {
                return 0;
            }
            
            int vertex;
            
            if (partition1.size() < partition2.size()) {
                for (int v : remaining) {
                    if (find(partition1.begin(), partition1.end(), v) == partition1.end()) {
                        vertex = v;
                        break;
                    }
                }
                partition1.push_back(vertex);
            } else {
                for (int v : remaining) {
                    if (find(partition2.begin(), partition2.end(), v) == partition2.end()) {
                        vertex = v;
                        break;
                    }
                }
                partition2.push_back(vertex);
            }
            
            remaining.erase(vertex);
        }
    }
    
    cout << "Y " << partition1.size() << endl;
    for (int vertex : partition1) {
        cout << vertex + 1 << " ";
    }
    cout << endl;
    
    return 0;
}