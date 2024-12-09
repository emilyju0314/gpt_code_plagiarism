#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
    int value;
    int weight;
};

vector<Vertex> tree;
vector<vector<int>> dp;

int knapsack(int vertex, int weight) {
    if (vertex == 0 || weight <= 0) {
        return 0;
    }
    
    if (dp[vertex][weight] != -1) {
        return dp[vertex][weight];
    }
    
    int ans = knapsack(vertex / 2, weight);
    
    if (tree[vertex].weight <= weight) {
        ans = max(ans, knapsack(vertex / 2, weight - tree[vertex].weight) + tree[vertex].value);
    }
    
    return dp[vertex][weight] = ans;
}

int main() {
    int N;
    cin >> N;
    
    tree.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> tree[i].value >> tree[i].weight;
    }
    
    dp.assign(N + 1, vector<int>(100001, -1));
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int v, L;
        cin >> v >> L;
        
        cout << knapsack(v, L) << endl;
    }
    
    return 0;
}