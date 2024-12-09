#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;

    int K_min = N;
    for (int K = 2; K <= N; ++K) {
        string S = "";
        for (int i = 0; i < N; ++i) {
            S += T[(K - 1 - (i % (2 * K - 2))) % K];
        }
        
        if (S == T) {
            K_min = min(K_min, K);
        }
    }

    cout << K_min << endl;

    return 0;
}