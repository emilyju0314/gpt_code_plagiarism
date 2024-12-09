#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> leftChild, rightChild;
vector<int> inOrderTraversal;
vector<bool> visited;

bool satisfyConstraints(int node) {
    if(visited[node]) return true;
    
    visited[node] = true;
    
    for(int leftChildNode : leftChild[node]) {
        if(!satisfyConstraints(leftChildNode)) return false;
    }
    
    inOrderTraversal.push_back(node);
    
    for(int rightChildNode : rightChild[node]) {
        if(!satisfyConstraints(rightChildNode)) return false;
    }
    
    return true;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    visited.resize(n+1, false);
    
    for(int i = 0; i < c; i++) {
        int a, b;
        string direction;
        cin >> a >> b >> direction;
        
        if(direction == "LEFT") {
            leftChild[a].push_back(b);
        } else {
            rightChild[a].push_back(b);
        }
    }
    
    if(!satisfyConstraints(1)) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int node : inOrderTraversal) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}