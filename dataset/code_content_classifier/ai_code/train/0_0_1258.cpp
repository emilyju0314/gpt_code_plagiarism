#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pi(n);
    vector<int> costs(n);
    vector<unordered_set<int>> colors(n);
    
    for (int i = 0; i < n; i++) {
        cin >> pi[i];
        pi[i]--; // to make it 0-indexed
        colors[i].insert(0); // Always start with color 0
        colors[pi[i]].insert(colors[i].begin(), colors[i].end());
        
        int cost = 0;
        while (colors[pi[i]].count(cost) > 0) {
            cost++;
        }
        costs[i] = cost;
        
        cout << cost + 1 << " ";
    }
    
    return 0;
}