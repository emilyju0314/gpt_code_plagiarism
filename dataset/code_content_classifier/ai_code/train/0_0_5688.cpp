#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    long long value;
    int level;
};

void printNodes(vector<vector<long long>>& tree, long long x) {
    vector<long long> nodes;
    
    while(x > 0) {
        nodes.push_back(x);
        x /= 2;
    }
    
    for(int i = nodes.size() - 1; i >= 0; i--) {
        cout << nodes[i] << " ";
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        int type;
        long long x, k;
        cin >> type >> x;
        
        if(type == 3) {
            printNodes(tree, x);
        } else {
            cin >> k;
            
            if(type == 1) {
                long long level = log2(x);
                long long start = pow(2, level);
                long long end = pow(2, level + 1) - 1;
                
                for(long long j = start; j <= end; j++) {
                    tree[level][j] = (tree[level][j] + k) % (pow(2, level));
                }
            } else if(type == 2) {
                // Implement shift nodes logic here
            }
        }
    }
    
    return 0;
}