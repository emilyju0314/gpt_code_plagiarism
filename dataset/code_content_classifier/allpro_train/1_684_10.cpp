#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

const int INF = 5000;
typedef unsigned char byte;

vector<string> field;
unordered_map<char, vector<pair<int,int>>> holes_of;
int dp[55][55][55][55];
bool visited[55][55][55][55];

int calc(byte t, byte l, byte b, byte r) {
    if(visited[t][l][b][r]) return dp[t][l][b][r];
    if(t > b || l > r) return -INF;
    if(field[t][l] == '#') return -INF;
    visited[t][l][b][r] = true;
    int &res = dp[t][l][b][r];
    if(t == b && l == r) {
        res = 0;
    } else {
        res = max(res, calc(t+1, l, b, r));
        res = max(res, calc(t, l+1, b, r));
        if(islower(field[t][l])) {
            // Pick and place
            for(const auto &to : holes_of[field[t][l]]) {
                //cout << field[t][l] << ' ' << to.first << ' ' << to.second << endl;
                if(to.first == b && to.second == r) continue;
                if(to.first < t || to.second < l) continue;
                res = max(res, calc(t+1, l, to.first, to.second) + 1 + calc(to.first, to.second, b, r));
                res = max(res, calc(t, l+1, to.first, to.second) + 1 + calc(to.first, to.second, b, r));
            }
        }
    }
    if(res < 0) res = -INF;
    return res;
}

bool solve() {
    int H, W;
    if(!(cin >> H >> W)) return false;
    if(!H && !W) return false;

    field.clear();
    field.resize(H);
    holes_of.clear();
    for(int i = 0; i < H; ++i) {
        cin >> field[i];
        for(int j = 0; j < W; ++j) {
            if(isupper(field[i][j])) {
                const char c = tolower(field[i][j]);
                holes_of[c].push_back(make_pair(i, j));
            }
        }
    }
    field.push_back(string(W, '#'));
    field.back()[W-1] = '.';
    fill_n((int*)dp, sizeof(dp)/sizeof(int), -INF);
    fill_n((bool*)visited, sizeof(visited)/sizeof(bool), false);

    int res = calc(0, 0, H, W-1);
    if(res < 0) res = -1;
    cout << res << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(solve()) ;
    return 0;
}