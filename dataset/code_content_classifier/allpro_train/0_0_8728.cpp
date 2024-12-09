#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int min_cost = 1e9;
    
    int min_price = A[0];
    int max_profit = 0;
    
    for(int i = 1; i < N; i++) {
        min_price = min(min_price, A[i-1]);
        max_profit = max(max_profit, A[i] - min_price);
    }
    
    int count = 0;
    
    for(int i = 1; i < N; i++) {
        if(A[i] - A[i-1] == max_profit) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}