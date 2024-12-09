#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i] - i);
    }
    
    cout << ans << endl;
    
    return 0;
}