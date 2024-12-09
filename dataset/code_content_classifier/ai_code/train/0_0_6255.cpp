#include <iostream>
#include <vector>
#include <string>
#define MOD 998244353
using namespace std;

int countChaoticMerges(string x, string y) {
    int n = x.length();
    int m = y.length();

    long long result = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int len_x = 1; len_x <= n - i + 1; len_x++) {
                for(int len_y = 1; len_y <= m - j + 1; len_y++) {
                    string sub_x = x.substr(i - 1, len_x);
                    string sub_y = y.substr(j - 1, len_y);

                    long long count = 0;
                    for(int k = 0; k < sub_x.length(); k++) {
                        for(int l = 0; l < sub_y.length(); l++) {
                            if(sub_x[k] != sub_y[l]) {
                                count++;
                            }
                        }
                    }

                    if(count == sub_x.length() * sub_y.length()) {
                        result++;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    string x, y;
    cin >> x >> y;

    long long answer = 0;

    for(int i = 1; i <= x.length(); i++) {
        for(int j = 1; j <= y.length(); j++) {
            for(int k = i; k <= x.length(); k++) {
                for(int l = j; l <= y.length(); l++) {
                    answer += countChaoticMerges(x.substr(i-1, k-i+1), y.substr(j-1, l-j+1));
                    answer %= MOD;
                }
            }
        }
    }

    cout << answer % MOD << endl;

    return 0;
}