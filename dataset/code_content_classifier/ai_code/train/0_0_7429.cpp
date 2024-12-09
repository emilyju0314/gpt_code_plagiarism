#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, D;
        cin >> N >> D;

        int sum = D;
        for (int i = 1; i < N; i++) {
            int x = 0;
            for (int j = 7; j >= 0; j--) {
                int bit = (D >> j) & 1;
                if (bit == 0) {
                    x ^= (1 << j);
                    if (x > 127) break;
                }
            }
            sum += x;
            D ^= x;
        }

        cout << sum << endl;
    }

    return 0;
}