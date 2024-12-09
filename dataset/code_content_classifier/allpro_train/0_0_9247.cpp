#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> X(N), P(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> P[i];
    }
    
    long long time = 0;
    
    for(int i = N-1; i >= 0; i--) {
        if(X[i] < S) {
            time += P[i];
            S -= 1;
        } else {
            time += P[i];
        }
    }
    
    cout << time << endl;
    
    return 0;
}