#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_power(long long x) {
    if (x <= 1) return false;
    for (long long i = 2; i <= sqrt(x); i++) {
        long long val = i;
        while (val <= x) {
            if (val == x) {
                return true;
            }
            val *= i;
        }
    }
    return false;
}

int main() {
    int Q;
    cin >> Q;

    vector<pair<long long, long long>> queries(Q);
    for (int i = 0; i < Q; i++) {
        long long L, R;
        cin >> L >> R;
        queries[i] = make_pair(L, R);
    }

    for (int i = 0; i < Q; i++) {
        long long count = 0;
        for (long long x = queries[i].first; x <= queries[i].second; x++) {
            if (is_power(x)) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}