#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    long long lcm = T[0];
    for (int i = 1; i < N; i++) {
        long long a = lcm, b = T[i];
        while (a % b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        lcm = lcm / b * T[i];
    }

    cout << lcm << endl;

    return 0;
}