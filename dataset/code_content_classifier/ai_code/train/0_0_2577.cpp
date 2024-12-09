#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> weights(N);
    for(int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    
    int min_diff = INT_MAX;
    
    for(int i = 1; i < N; i++) {
        int sum1 = 0, sum2 = 0;
        
        for(int j = 0; j < i; j++) {
            sum1 += weights[j];
        }
        
        for(int j = i; j < N; j++) {
            sum2 += weights[j];
        }
        
        min_diff = min(min_diff, abs(sum1 - sum2));
    }
    
    cout << min_diff << endl;
    
    return 0;
}