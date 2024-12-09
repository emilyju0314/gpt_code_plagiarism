#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    vector<int> C(N+1);
    for (int i = 0; i < N+1; i++) {
        cin >> C[i];
    }
    
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int D, E;
        cin >> D >> E;
        
        int max_score = 0;
        for (int i = 0; i < N; i++) {
            int cur_score = 0;
            int used_front = 0;
            
            if (D <= A[i] && E >= C[i]) {
                cur_score++;
                used_front = 1;
            }
            
            if (D <= B[i] && E >= C[i]) {
                cur_score++;
            }
            
            max_score = max(max_score, cur_score);
        }
        
        if (max_score == 0) {
            cout << -1 << endl;
        } else {
            cout << max_score << endl;
        }
    }
    
    return 0;
}