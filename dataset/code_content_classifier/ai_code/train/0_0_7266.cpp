#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, P;

    while (true) {
        cin >> N >> P;

        if (N == 0 && P == 0) {
            break;
        }

        vector<long long> coefficients(N + 1);
        for (int i = 0; i <= N; i++) {
            cin >> coefficients[i];
        }

        int count = 0;
        for (int z = 0; z < P; z++) {
            long long t = 0;
            for (int i = 0; i <= N; i++) {
                t = (t * z + coefficients[i]) % P;
            }
            if (t == 0) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}