#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int D, K, L;
    
    while (true) {
        cin >> D >> K >> L;
        
        if(D == 0 && K == 0 && L == 0) {
            break;
        }
        
        // Read prices of parts for each lesson
        vector<vector<int>> prices(D, vector<int>(K));
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < K; j++) {
                cin >> prices[i][j];
            }
        }
        
        int M, N, P, total_cost = 0;
        cin >> M >> N >> P;
        
        // Read the requirements for each task type
        vector<vector<int>> requirements(M, vector<int>(K));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                cin >> requirements[i][j];
            }
        }
        
        // Read the contents of each bag
        vector<vector<int>> bags(P, vector<int>(K));
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < K; j++) {
                cin >> bags[i][j];
            }
        }
        
        // Iterate through all possible bag combinations
        do {
            int min_cost = INT_MAX;
            for (int i = 0; i < P; i++) {
                int cost = 0;
                for (int j = 0; j < K; j++) {
                    if (bags[i][j] < requirements[j]) {
                        cost += requirements[j] - bags[i][j];
                    }
                }
                min_cost = min(min_cost, cost);
            }
            total_cost = max(total_cost, min_cost);
        } while(next_permutation(bags.begin(), bags.end()));
        
        // Output the minimum total cost
        if (total_cost == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << total_cost << endl;
        }
    }
    
    return 0;
}