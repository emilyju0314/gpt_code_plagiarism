#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isKMultihedgehog(vector<int>& degrees, int n, int k) {
    vector<int> subtreeSizes(n, 1);
    queue<int> leaves;
    
    // Find leaves and calculate subtree sizes
    for(int i = 0; i < n; i++) {
        if(degrees[i] == 1) {
            leaves.push(i);
        }
    }
    
    bool isValid = true;
    
    for(int i = 1; i < k; i++) {
        if(leaves.empty()) {
            isValid = false;
            break;
        }
        
        queue<int> newLeaves;
        
        while(!leaves.empty()) {
            int leaf = leaves.front();
            leaves.pop();
            
            int parent = leaf;
            degrees[parent]--;
            
            if(degrees[parent] < 1) {
                isValid = false;
                break;
            }
            
            for(int j = 0; j < degrees[parent]; j++) {
                int child = parent;
                cin >> child;
                degrees[child]--;
                
                if(degrees[child] < 1) {
                    isValid = false;
                    break;
                }
                
                subtreeSizes[child] += subtreeSizes[parent];
                
                if(degrees[child] == 1) {
                    newLeaves.push(child);
                }
            }
        }
        
        swap(leaves, newLeaves);
    }
    
    // Check if the center vertex has degree at least 3
    for(int i = 0; i < n; i++) {
        if(degrees[i] >= 3) {
            return isValid && degrees[i] == 3;
        }
    }
    
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> degrees(n, 0);
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        degrees[u]++;
        degrees[v]++;
    }
    
    bool result = isKMultihedgehog(degrees, n, k);
    
    if(result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}