#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> A[i];
    }
    
    int M;
    cin >> M;
    
    vector<int> X(M);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
    }
    
    vector<int> prefix_sum(N);
    prefix_sum[0] = 0;
    for(int i = 0; i < N-1; i++) {
        prefix_sum[i+1] = prefix_sum[i] + A[i];
    }
    
    int max_diff = prefix_sum[N-1];
    int min_val = prefix_sum[1];
    int sum = 0;
    
    for(int i = 0; i < M; i++) {
        sum += X[i];
        int diff = sum - min_val;
        max_diff = max(max_diff, diff);
    }
    
    for(int i = 0; i < M; i++) {
        cout << max_diff << endl;
    }
    
    return 0;
}