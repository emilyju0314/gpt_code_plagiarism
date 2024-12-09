#include <iostream>
#include <vector>
using namespace std;

const int M = 1000003;

int main() {
    vector<int> factorial(M);
    factorial[0] = 1;
    for (int i = 1; i < M; i++) {
        factorial[i] = (factorial[i-1] * i) % M;
    }

    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        int result = 0;
        for (int i = 0; i <= min(n, k); i++) {
            int a = factorial[n] % M;
            int b = factorial[i] % M;
            int c = factorial[n-i] % M;
            int temp = (((a * b) % M) * c) % M;
            result = (result + temp) % M;
        }

        cout << result << endl;
    }

    return 0;
}