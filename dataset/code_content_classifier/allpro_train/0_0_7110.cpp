#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> beads(101); // assuming there can be maximum of 100 beads

int findLongestPath(int v, vector<vector<int>>& adj_list) {
    int max_length = 0;
    for(int i = 0; i < adj_list[v].size(); i++) {
        int u = adj_list[v][i];
        max_length = max(max_length, findLongestPath(u, adj_list) + 1);
    }
    return max_length;
}

int main() {
    cin >> n;
    
    vector<vector<int>> adj_lists(n);
    
    for(int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        for(int j = 0; j < ni-1; j++) {
            int a, b;
            cin >> a >> b;
            adj_lists[i].push_back(a);
            adj_lists[i].push_back(b);
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, findLongestPath(i, adj_lists));
    }
    
    cout << result << endl;
    
    return 0;
}