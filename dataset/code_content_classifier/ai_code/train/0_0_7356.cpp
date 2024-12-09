#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        
        vector<int> futons(N);
        vector<int> demands(M);
        
        for (int i = 0; i < N; i++) {
            cin >> futons[i];
        }
        
        for (int i = 0; i < M; i++) {
            cin >> demands[i];
        }
        
        int min_discomfort = INT_MAX;
        
        for (int mask = 0; mask < (1 << N); mask++) {
            vector<int> closet(N, 0);
            
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    closet[N - 1 - i] = 1;
                }
            }
            
            int discomfort = 0;
            vector<int> total_supply(M, 0);
            
            for (int j = 0; j < M; j++) {
                int sum_supply = 0;
                
                for (int i = 0; i < N; i++) {
                    if (closet[i] == 1) {
                        sum_supply += futons[i];
                    }
                }
                
                discomfort += abs(sum_supply - demands[j]);
            }
            
            min_discomfort = min(min_discomfort, discomfort);
        }
        
        cout << min_discomfort << endl;
    }
    
    return 0;
}