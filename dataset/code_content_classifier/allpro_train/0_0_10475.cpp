#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<vector<int>> children;
int min_eval = 0, max_eval = 0;

int negamax(int node, int alpha, int beta) {
    if(children[node].empty()) {
        min_eval++;
        max_eval++;
        return p[node];
    }
    
    int val = INT_MIN;
    for(int child : children[node]) {
        val = max(val, -negamax(child, -beta, -alpha));
        if(val >= beta) {
            return val;
        }
        alpha = max(alpha, val);
    }
    
    return val;
}

int main() {
    int n;
    cin >> n;
    
    p.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    children.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int child;
            cin >> child;
            children[i].push_back(child);
        }
    }
    
    negamax(1, INT_MIN, INT_MAX);
    
    cout << min_eval << " " << max_eval << endl;
    
    return 0;
}