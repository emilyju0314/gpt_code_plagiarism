#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int w = 0;
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'o') {
                w++;
            }
        }
        ans = (ans + (1LL << w)) % MOD;
    }

    for(int j = 0; j < m; j++) {
        int w = 0;
        for(int i = 0; i < n; i++) {
            if(board[i][j] == 'o') {
                w++;
            }
        }
        ans = (ans + (1LL << w)) % MOD;
    }

    cout << ans << endl;

    return 0;
}