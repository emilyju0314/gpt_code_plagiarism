#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 998244353;

int countValidColorings(int n, vector<string>& dominoes) {
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        char left = dominoes[i][0];
        char right = dominoes[i][1];

        if(left == '?' && right == '?') {
            ans = (ans * 2) % MOD;
        } else if(left == '?' || right == '?') {
            ans = (ans * 1) % MOD;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for(int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    cout << countValidColorings(n, dominoes) << endl;

    return 0;
}