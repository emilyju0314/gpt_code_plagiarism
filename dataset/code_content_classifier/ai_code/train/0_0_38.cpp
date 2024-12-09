#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long find_smallest_integer(vector<pair<long long, long long>>& progressions) {
    long long x = progressions[0].first;

    for (pair<long long, long long> progression : progressions) {
        x = gcd(x, progression.first);
    }

    for (pair<long long, long long> progression : progressions) {
        if (progression.first % x != 0) {
            return -1;
        }
    }

    return x % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> progressions;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        progressions.push_back({a, b});
    }

    cout << find_smallest_integer(progressions) << endl;

    return 0;
}