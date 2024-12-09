#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    long long totalMP = 0;
    int cookieCount = min(K, N-1);
    
    for(int i=0; i<=cookieCount; i++) {
        totalMP += A[i];
    }
    
    long long remainingMP = M * N - totalMP;
    
    long long time = 0;
    while(remainingMP > 0) {
        time++;
        remainingMP -= min(remainingMP, M);
        if(K > 0) {
            K--;
            remainingMP += 1;
        }
    }
    
    cout << time << endl;
    
    return 0;
}