#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> qualifications(n);
    for(int i = 0; i < n; i++) {
        cin >> qualifications[i];
    }
    
    int m;
    cin >> m;
    
    vector<pair<int, pair<int, int>>> applications;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        applications.push_back({c, {a-1, b-1}});
    }
    
    sort(applications.begin(), applications.end());
    
    vector<int> parent(n, -1);
    int total_cost = 0;
    
    for(auto application : applications) {
        int cost = application.first;
        int a = application.second.first;
        int b = application.second.second;
        
        while(parent[a] != -1) {
            a = parent[a];
        }
        
        if(a == b) {
            continue;
        }
        
        if(qualifications[a] <= qualifications[b]) {
            parent[a] = b;
            total_cost += cost;
        }
    }
    
    for(int i = 1; i < n; i++) {
        if(parent[i] == -1) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}