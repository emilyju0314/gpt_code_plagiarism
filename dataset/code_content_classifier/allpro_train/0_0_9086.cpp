#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<string> bytes(N);
        for (int i = 0; i < N; i++) {
            cin >> bytes[i];
        }

        long long total = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 8; j++) {
                if (bytes[i][j] == 'x') {
                    total *= 2;
                    total %= 1000000;
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}