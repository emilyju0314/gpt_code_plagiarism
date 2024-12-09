#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    long long answer = 0;
    
    for (int x = 0; x < A; x++) {
        for (int y = 0; y < B; y++) {
            for (int z = 0; z < C; z++) {
                int dx = min(A - 1 - x, x);
                int dy = min(B - 1 - y, y);
                int dz = min(C - 1 - z, z);
                if (dx*dx + dy*dy + dz*dz <= D*D) {
                    answer++;
                }
            }
        }
    }

    cout << answer % MOD << endl;

    return 0;
}