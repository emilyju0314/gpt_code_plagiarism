#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool checkSequence(vector<long long>& sequence, long long n, long long m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m - sequence.size() + 1; j++) {
            bool found = true;
            for(int k = 0; k < sequence.size(); k++) {
                if(gcd(i, j + k - 1) != sequence[k]) {
                    found = false;
                    break;
                }
            }
            if(found) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> sequence(k);
    for(int i = 0; i < k; i++) {
        cin >> sequence[i];
    }

    if(checkSequence(sequence, n, m)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}