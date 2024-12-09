#include <iostream>
using namespace std;

long long findReleasedPrisoner(int N, int k) {
    long long prisoner = 0;
    for (int i = 1; i <= N; i++) {
        prisoner = (prisoner + k) % i;
    }
    return prisoner;
}

int main() {
    int N, k;
    cin >> N >> k;

    long long result = findReleasedPrisoner(N, k);
    cout << result << endl;

    return 0;
}