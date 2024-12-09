#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

struct Fibonacci {
    long long a, b, c;
};

vector<long long> fib;

void generateFibonacci() {
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 2; i <= 50000; i++) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % MOD);
    }
}

void processQuery(vector<long long>& A, int l, int r, int type, long long x) {
    for (int i = l - 1; i < r; i++) {
        if (type == 1) {
            A[i] = min(A[i], x);
        } else if (type == 2) {
            A[i] = max(A[i], x);
        } else if (type == 3) {
            A[i] += x;
            if (A[i] < 0) {
                A[i] = 0;
            }
        }
    }
}

long long calculateSum(vector<long long>& A1, vector<long long>& A2, int l, int r) {
    long long sum = 0;
    for (int i = l - 1; i < r; i++) {
        int val = A1[i] + A2[i];
        sum = (sum + fib[val]) % MOD;
    }
    return sum;
}

int main() {
    generateFibonacci();

    int N, Q;
    cin >> N >> Q;

    vector<long long> A1(N);
    vector<long long> A2(N);

    for (int i = 0; i < N; i++) {
        cin >> A1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        
        if (type == 1 || type == 2 || type == 3) {
            int k, l, r;
            long long x;
            cin >> k >> l >> r >> x;

            if (k == 1) {
                processQuery(A1, l, r, type, x);
            } else {
                processQuery(A2, l, r, type, x);
            }
        } else if (type == 4) {
            int l, r;
            cin >> l >> r;
            long long sum = calculateSum(A1, A2, l, r);
            cout << sum << endl;
        }
    }

    return 0;
}