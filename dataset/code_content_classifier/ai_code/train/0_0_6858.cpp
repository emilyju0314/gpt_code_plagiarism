#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long G(int X, int Y, int N, int M) {
    long long ans = 0;
    for (int i = X; i <= N; i++) {
        for (int j = Y; j <= M; j++) {
            int dx = abs(i - X);
            int dy = abs(j - Y);
            if (dx + dy == 3 && dx > 0 && dy > 0) {
                ans++;
            }
        }
    }
    return ans % MOD;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int X, Y, N, M;
        cin >> X >> Y >> N >> M;
        
        cout << G(X, Y, N, M) << endl;
    }
    
    return 0;
}