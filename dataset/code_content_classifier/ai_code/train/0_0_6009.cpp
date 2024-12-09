#include <iostream>
#include <vector>

using namespace std;

bool createTree(vector<int>& c, int index, int current_nodes, int total_nodes) {
    // Base case: all nodes are added
    if (index >= c.size()) {
        return current_nodes == total_nodes;
    }
    
    // Try adding different number of children to the current node
    for (int i = 2; i <= c[index]; i++) {
        if (current_nodes + i <= total_nodes && createTree(c, index + 1, current_nodes + i, total_nodes)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> c(n);
    int total_nodes = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        total_nodes += c[i];
    }
    
    if (total_nodes == 2*n && createTree(c, 1, 2, total_nodes)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}