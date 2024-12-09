#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<long long> cost(k+1, 0);
    cost[0] = 0;
    
    for(int i = 0; i < n; i++) {
        vector<long long> new_cost = cost;
        
        for(int j = 0; j <= k; j++) {
            if(j <= n) {
                new_cost[j] = max(new_cost[j], cost[j]);
                new_cost[j+1] = max(new_cost[j+1], cost[j] + i+1);
            }
        }
        
        cost = new_cost;
    }
    
    long long total_cost = -1;
    
    for(int i = 0; i <= n; i++) {
        if(cost[i] >= k) {
            total_cost = i;
            break;
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}