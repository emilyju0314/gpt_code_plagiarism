#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

struct Doll {
    int out, in;
};

bool compare(Doll a, Doll b) {
    return a.out > b.out;
}

int main() {
    int n;
    cin >> n;

    vector<Doll> dolls(n);
    for (int i = 0; i < n; i++) {
        cin >> dolls[i].out >> dolls[i].in;
    }

    sort(dolls.begin(), dolls.end(), compare);

    vector<long long> dp(n, 0);
    long long result = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dolls[i].out <= dolls[j].in) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;

    return 0;
}