#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    
    vector<int> C(N);
    
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    long long total_cost = 0;
    
    for(int i = 0; i < N; i++) {
        total_cost = (total_cost + (long long)C[i] * (long long)(N - i) * (long long)pow(2, i) % MOD) % MOD;
    }
    
    cout << total_cost << endl;
    
    return 0;
}