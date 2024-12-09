#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solve() {
    int L, D;
    if(!(cin >> L >> D)) return false;
    if(!L && !D) return false;

    string strs[3];
    for(int i = 0; i < 3; ++i) {
        cin >> strs[i];
    }

    vector<int> diff_by_one[3];
    vector<int> all_diff(L+1, 0);
    for(int i = 0; i < 3; ++i) {
        diff_by_one[i].resize(L+1, 0);
        const int next = (i+1) % 3;
        const int prev = (i+2) % 3;
        for(int j = 0; j < L; ++j) {
            if(strs[i][j] != strs[next][j] && strs[next][j] == strs[prev][j]) {
                diff_by_one[i][j] = 1;
            }
        }
        for(int j = L-1; j >= 0; --j) {
            diff_by_one[i][j] += diff_by_one[i][j+1];
        }
    }
    for(int i = 0; i < L; ++i) {
        if(strs[0][i] != strs[1][i] && strs[1][i] != strs[2][i] && strs[2][i] != strs[0][i]) {
            all_diff[i] = 1;
        }
    }
    for(int i = L-1; i >= 0; --i) {
        all_diff[i] += all_diff[i+1];
    }

    string res;
    vector<int> remain(3, D);
    for(int i = 0; i < L; ++i) {
        char ch = '\x7f';
        for(int idx = 0; idx < 4; ++idx) {
            const char test_ch = idx == 0 ? 'A' : strs[idx-1][i];
            int sum = 0;
            int r[3] = {0};
            int u[3] = {0};
            for(int j = 0; j < 3; ++j) {
                const int next_rem = remain[j] - (test_ch == strs[j][i] ? 0 : 1);
                r[j] = next_rem - diff_by_one[j][i+1];
                u[j] = all_diff[i+1] - r[j];
                sum += max(0, u[j]);
            }
            bool ok = sum <= all_diff[i+1];
            if(!ok) {
                if(u[0] <= 0 && u[1] <= 0) {
                    ok = sum - min({diff_by_one[2][i+1], -u[0], -u[1]}) <= all_diff[i+1];
                }
                if(u[1] <= 0 && u[2] <= 0) {
                    ok = sum - min({diff_by_one[0][i+1], -u[1], -u[2]}) <= all_diff[i+1];
                }
                if(u[2] <= 0 && u[0] <= 0) {
                    ok = sum - min({diff_by_one[1][i+1], -u[2], -u[0]}) <= all_diff[i+1];
                }
            }
            if(ok) {
                ch = min(ch, test_ch);
                //cout << i << ' ' << ch << endl;
            }
            if(ch == 'A') break;
        }
        if(ch == '\x7f') {
            res = "-1";
            break;
        } else {
            res += ch;
            //cout << res << endl;
            for(int j = 0; j < 3; ++j) {
                remain[j] -= (ch == strs[j][i] ? 0 : 1);
            }
        }
    }
    cout << res << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(solve()) ;
    return 0;
}