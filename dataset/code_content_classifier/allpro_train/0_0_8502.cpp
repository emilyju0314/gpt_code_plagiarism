#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> trees(n);
    for(int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    
    sort(trees.begin(), trees.end());
    
    long long res = 0;
    vector<int> people;
    
    for(int i = 0; i < m; i++) {
        int nearest_tree = lower_bound(trees.begin(), trees.end(), people[i]) - trees.begin();
        
        if(nearest_tree == 0) {
            res += abs(trees[nearest_tree] - people[i]);
        } else if(nearest_tree == n) {
            res += abs(trees[n-1] - people[i]);
        } else {
            res += min(abs(trees[nearest_tree] - people[i]), abs(trees[nearest_tree-1] - people[i]));
        }
    }
    
    cout << res << endl;
    
    int dist = 0;
    for(int i = 0; i < m; i++) {
        if(i % 2 == 0) {
            cout << trees[dist] - 1 << " ";
        } else {
            cout << trees[n - dist - 1] + 1 << " ";
            dist++;
        }
    }
    
    return 0;
}