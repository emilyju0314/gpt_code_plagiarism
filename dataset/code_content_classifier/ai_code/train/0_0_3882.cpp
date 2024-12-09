
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the prices in descending order
    sort(A.rbegin(), A.rend());
    
    long long amount = 0;
    int coins = 0;
    
    // Keep track of the current payment using coins
    for(int i = 0; i < N; i++) {
        while(amount * 10 + 1 < A[i]) {
            amount = amount * 10 + 1;
            coins++;
        }
        amount += A[i];
    }
    
    cout << coins << endl;
    
    return 0;
}