#include<iostream>
#include<string>
using namespace std;

int grid[11][11];

void solve(string s) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    int H = 1, W = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') H++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') break;
        if (s[i] >= '0' && s[i] <= '9') {
            W += s[i] - '0';
        }
        else W++;
    }
    int now_h = 0, now_w = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            now_w = 0;
            now_h++;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            for (int w = now_w; w < now_w + int(s[i] - '0'); w++) {
                grid[now_h][w] = 0;
            }
            now_w += s[i] - '0';
        }
        else {
            grid[now_h][now_w] = 1;
            now_w++;
        }
    }
    grid[a][b] = 0, grid[c][d] = 1;
    string ans;
    int zeros = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j]) {
                if (zeros) {
                    ans += char('0' + zeros);
                    zeros = 0;
                }
                ans += 'b';
            }
            else zeros++;
        }
        if (zeros) {
            ans += char('0' + zeros);
            zeros = 0;
        }
        if (i != H - 1) ans += '/';
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    while (true) {
        cin >> S;
        if (S == "#") break;
        solve(S);
    }
    return 0;
}
