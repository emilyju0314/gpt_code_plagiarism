#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> ingredient_index;
vector<int> parent;
vector<int> cost;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unify(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
        cost[a] = min(cost[a], cost[b]);
    }
}

int main() {
    int N, M;
    cin >> N;
    
    parent.resize(N);
    cost.resize(N);
    
    for (int i = 0; i < N; i++) {
        string ingredient;
        int price;
        cin >> ingredient >> price;
        
        ingredient_index[ingredient] = i;
        parent[i] = i;
        cost[i] = price;
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        string source, target;
        cin >> source >> target;
        
        unify(ingredient_index[source], ingredient_index[target]);
    }
    
    int total_cost = 0;
    
    for (int i = 0; i < N; i++) {
        if (find(i) == i) {
            total_cost += cost[i];
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}