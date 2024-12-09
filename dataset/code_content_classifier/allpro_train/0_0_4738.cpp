#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> X(N), Y(N), P(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }
    
    long long sum = LLONG_MAX;
    
    for(int k = 0; k <= N; k++) {
        for(int mask = 0; mask < (1 << N); mask++) {
            vector<int> railroads;
            
            for(int i = 0; i < N; i++) {
                if(mask & (1 << i)) {
                    railroads.push_back(X[i]);
                } else {
                    railroads.push_back(Y[i]);
                }
            }
            
            long long dist = 0;
            for(int i = 0; i < N; i++) {
                int min_dist = INT_MAX;
                
                for(int j = 0; j < railroads.size(); j++) {
                    int d = abs(railroads[j] - X[i]) + abs(railroads[j] - Y[i]);
                    min_dist = min(min_dist, d);
                }
                
                dist += (long long) min_dist * P[i];
            }
            
            sum = min(sum, dist);
        }
        
        cout << sum << endl;
    }
    
    return 0;
}