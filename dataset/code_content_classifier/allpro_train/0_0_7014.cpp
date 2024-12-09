#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;
const int MAXC = 100005;

string A, B;
int c[4];
int dp[MAXN][4];

int countValidNumbers(int len, int c00, int c01, int c10, int c11) {
    if (len == 0) {
        return (c00 == 0 && c01 == 0 && c10 == 0 && c11 == 0) ? 1 : 0;
    }

    int& res = dp[len][c00*1 + c01*2 + c10*4 + c11*8];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            if (c00 - (i == 0 && j == 0) >= 0 &&
                c01 - (i == 0 && j == 1) >= 0 &&
                c10 - (i == 1 && j == 0) >= 0 &&
                c11 - (i == 1 && j == 1) >= 0) {
                int new_c00 = c00 - (i == 0 && j == 0);
                int new_c01 = c01 - (i == 0 && j == 1);
                int new_c10 = c10 - (i == 1 && j == 0);
                int new_c11 = c11 - (i == 1 && j == 1);
                res = (res + countValidNumbers(len - 1, new_c00, new_c01, new_c10, new_c11)) % MOD;
            }
        }
    }

    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> A >> B;
    cin >> c[0] >> c[1] >> c[2] >> c[3];

    int lenA = A.size();
    int lenB = B.size();

    int countB = countValidNumbers(lenB, c[0], c[1], c[2], c[3]);

    for (char& ch : A) {
        countB = (countB - (ch - '0' == 0)) % MOD;
    }
    
    int countA = (A.size() > 1 || A[0] == '1') ? 0 : (countValidNumbers(lenA - 1, c[0], c[1], c[2], c[3]) - (A[0] == '0'));

    int result = (countB - countA + MOD) % MOD;
    cout << result << endl;

    return 0;
}