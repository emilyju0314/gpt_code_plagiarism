#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    
    long long total_candies = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        total_candies += A[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i]) {
            total_candies -= min(A[i], B[i]);
        }
    }
    
    cout << total_candies << endl;
    
    return 0;
}