#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, A, B, C, T;
    
    while (true) {
        cin >> N >> M >> A >> B >> C >> T;
        if (N == 0 && M == 0 && A == 0 && B == 0 && C == 0 && T == 0) break;
        
        vector<int> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        
        vector<int> newS(N);
        while (T--) {
            for (int i = 0; i < N; i++) {
                newS[i] = (A * (i > 0 ? S[i - 1] : 0) + B * S[i] + C * (i < N - 1 ? S[i + 1] : 0)) % M;
            }
            S = newS;
        }
        
        for (int i = 0; i < N; i++) {
            cout << S[i] << (i == N - 1 ? "\n" : " ");
        }
    }
    
    return 0;
}