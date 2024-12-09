#include <iostream>

using namespace std;

int main() {
    int A;
    cin >> A;

    int N, M;

    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * (j-1) + 1 <= A) {
                N = i * (j-1) + 1;
                M = j;
                break;
            }
        }
        if (N != 0) {
            break;
        }
    }

    cout << N << " " << M << endl;

    for (int i = 1; i <= M; i++) {
        cout << i * 2 << " ";
    }

    return 0;
}