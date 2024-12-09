#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> cost(N, vector<int>(N-1));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-1; j++) {
            cin >> cost[i][j];
        }
    }
    
    vector<int> pairs(N, -1);
    
    for(int i = 0; i < N; i++) {
        int minCost = INT_MAX;
        int partner = -1;
        
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            
            if(pairs[j] == -1) {
                if(cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    partner = j;
                }
            } else {
                if(cost[i][j] < cost[i][pairs[j]] && cost[j][i] < cost[j][i]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        
        pairs[i] = partner;
    }
    
    for(int i = 0; i < N; i++) {
        cout << pairs[i]+1 << endl;
    }
    
    return 0;
}