#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool pairwise_coprime = true;
    bool setwise_coprime = false;
    int overall_gcd = A[0];
    
    for (int i = 1; i < N; i++) {
        overall_gcd = gcd(overall_gcd, A[i]);
        if (pairwise_coprime) {
            for (int j = 0; j < i; j++) {
                if (gcd(A[i], A[j]) != 1) {
                    pairwise_coprime = false;
                    break;
                }
            }
        }
    }

    if (pairwise_coprime) {
        cout << "pairwise coprime" << endl;
    } else if (overall_gcd == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}