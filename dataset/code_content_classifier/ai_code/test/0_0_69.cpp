#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

vector<int> fibonacci = {0, 1};

int F(int n) {
    while(n >= fibonacci.size()) {
        fibonacci.push_back((fibonacci[fibonacci.size()-1] + fibonacci[fibonacci.size()-2]) % MOD);
    }
    return fibonacci[n];
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A1(N), A2(N);
    for(int i = 0; i < N; i++) {
        cin >> A1[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    for(int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        if(type == 1 || type == 2) {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            for(int i = l-1; i < r; i++) {
                if(k == 1) {
                    A1[i] = min(A1[i], x);
                } else {
                    A1[i] = max(A1[i], x);
                }
            }
        } else if(type == 3) {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            for(int i = l-1; i < r; i++) {
                A1[i] = (A1[i] + x) % MOD;
            }
        } else {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for(int i = l-1, j = r-1; i < r; i++, j--) {
                sum = (sum + F(A1[i] + A2[j])) % MOD;
            }
            cout << sum << endl;
        }
    }

    return 0;
}