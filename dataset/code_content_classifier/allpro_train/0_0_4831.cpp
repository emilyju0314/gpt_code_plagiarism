#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        long long X, Y;
        cin >> X >> Y;

        long long max_steps = 0;
        long long count = 0;

        if (X > Y) {
            swap(X, Y);
        }

        for (long long a = 1; a <= X; a++) {
            for (long long b = a; b <= Y; b++) {
                long long steps = 0;
                
                while (b > 0) {
                    long long q = b % a;
                    b = a;
                    a = q;
                    steps++;
                }
                
                if (steps > max_steps) {
                    max_steps = steps;
                    count = 1;
                } else if (steps == max_steps) {
                    count++;
                }
            }
        }
        
        cout << max_steps << " " << count % MOD << endl;
    }

    return 0;
}