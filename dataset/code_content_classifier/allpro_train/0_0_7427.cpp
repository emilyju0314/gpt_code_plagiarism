#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    vector<long long> A(X+Y+Z), B(X+Y+Z), C(X+Y+Z);
    for (int i = 0; i < X+Y+Z; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<long long> total(X+Y+Z);
    for (int i = 0; i < X+Y+Z; i++) {
        total[i] = A[i] + B[i] + C[i];
    }

    sort(total.rbegin(), total.rend());

    long long ans = 0;
    long long sumA = 0, sumB = 0, sumC = 0;
    for (int i = 0; i < X; i++) {
        sumA += A[i];
    }
    for (int i = X; i < X+Y; i++) {
        sumB += B[i];
    }
    for (int i = X+Y; i < X+Y+Z; i++) {
        sumC += C[i];
    }

    ans = sumA + sumB + sumC;
    for (int i = Y; i < X+Y; i++) {
        sumB += B[i];
        ans = max(ans, sumA + sumB + sumC);
    }

    cout << ans << endl;

    return 0;
}