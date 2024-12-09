#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int g = gcd(N, M);
    int L = N / g * M;
    string X = "";
    for (int i = 0; i < L; i++) {
        X += S[i / (L / N)];
    }
    for (int i = 0; i < L; i++) {
        if (X[i / (L / M)] != T[i % M]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << L << endl;

    return 0;
}