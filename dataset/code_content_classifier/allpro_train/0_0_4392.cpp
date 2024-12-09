#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long N, M, A, B;
        cin >> N >> M >> A >> B;

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (A * i + B) / M;
        }

        cout << sum << endl;
    }

    return 0;
}