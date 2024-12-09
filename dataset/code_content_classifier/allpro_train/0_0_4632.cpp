#include <iostream>
#include <vector>

using namespace std;

int countRestaurants(int n, int m, vector<int> cats, vector<vector<int>>& tree, int currentVertex, int parent, int consecutiveCats) {
    if (cats[currentVertex] == 1) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }
    
    if (consecutiveCats > m) {
        return 0;
    }
    
    if (tree[currentVertex].size() == 1 && currentVertex != 1) {
        return 1;
    }
    
    int count = 0;
    for (int child : tree[currentVertex]) {
        if (child != parent) {
            count += countRestaurants(n, m, cats, tree, child, currentVertex, consecutiveCats);
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> cats(n + 1);
    vector<vector<int>> tree(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    int result = countRestaurants(n, m, cats, tree, 1, -1, 0);
    cout << result << endl;
    
    return 0;
}