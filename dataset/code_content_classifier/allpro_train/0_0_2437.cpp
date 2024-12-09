#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ask_query(vector<int>& p, vector<int>& q) {
    cout << p.size() << " " << q.size();
    for(int node : p) {
        cout << " " << node;
    }
    for(int node : q) {
        cout << " " << node;
    }
    cout << endl;
    
    int dist;
    cin >> dist;
    return dist;
}

void find_diameter(int n) {
    // Initialize the nodes
    vector<int> nodes;
    for(int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }
    
    // Initialize the maximum distance found so far
    int max_dist = 0;
    
    // Ask at most 9 questions
    for(int i = 0; i < min(9, n-1); i++) {
        // Split the nodes into two random nonempty disjoint sets
        random_shuffle(nodes.begin(), nodes.end());
        vector<int> p(nodes.begin(), nodes.begin() + (n / 2));
        vector<int> q(nodes.begin() + (n / 2), nodes.end());
        
        int dist = ask_query(p, q);
        max_dist = max(max_dist, dist);
    }
    
    // Output the maximum distance found
    cout << "-1 " << max_dist << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        find_diameter(n);
    }
    
    return 0;
}