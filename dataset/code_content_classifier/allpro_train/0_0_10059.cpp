#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> X(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }
    
    int A;
    cin >> A;
    
    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    long long total_cost = 0;
    int max_lift = K;
    
    for(int i = 0; i < N; i++) {
        if(X[i] > max_lift) {
            int required_drink = (X[i] - max_lift + A - 1) / A;
            int min_cost = INT_MAX;
            for(int j = max(i-1, 0); j >= 0; j--) {
                if(C[j] < min_cost) {
                    min_cost = C[j];
                }
            }
            if(min_cost == INT_MAX) {
                cout << -1 << endl;
                return 0;
            }
            total_cost += (required_drink * min_cost);
            max_lift += (required_drink * A);
        }
        max_lift += X[i];
    }
    
    cout << total_cost << endl;
    
    return 0;
}