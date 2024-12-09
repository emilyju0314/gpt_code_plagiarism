#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N+1);
    for (int i = 0; i <= N; i++) {
        cin >> A[i];
    }
    
    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    long long sum = 1;
    long long vertices = 1;
    
    for (int i = 1; i <= N; i++) {
        if (A[i] > sum) {
            cout << -1 << endl;
            return 0;
        }
        
        vertices += min(sum, (long long) 2 * sum - A[i]);
        sum -= A[i];
        
        if (sum < 0) {
            cout << -1 << endl;
            return 0;
        }
        
        sum *= 2;
    }
    
    cout << vertices << endl;
    
    return 0;
}