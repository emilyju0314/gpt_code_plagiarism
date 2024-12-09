#include <iostream>
#include <vector>

using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    
    int height;
    cin >> height;
    
    return height;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> min_height(n, 1e9);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int height = query(i, j);
            min_height[i - 1] = min(min_height[i - 1], height);
        }
    }
    
    for (int i = 0; i < n; i++) {
        min_height[i] = query(i + 1, 1);
    }
    
    int min_tree = min_height[0];
    for (int i = 1; i < n; i++) {
        min_tree = min(min_tree, min_height[i]);
    }
    
    cout << "! " << min_tree << endl;
    
    return 0;
}