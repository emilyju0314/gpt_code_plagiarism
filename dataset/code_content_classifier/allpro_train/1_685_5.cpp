#include <bits/stdc++.h>
using namespace std;

int grundy[21][21][21][21];

int calc_grundy(int y1, int x1, int y2, int x2, vector<string> const& v) {
    if(y2 <= y1 || x2 <= x1) {
        return grundy[y1][x1][y2][x2] = 0;
    }
    int& r = grundy[y1][x1][y2][x2];
    if(r != -1) {
        return r;
    }
    set<int> s;
    for(int i=y1; i<y2; ++i) {
        for(int j=x1; j<x2; ++j) {
            if(v[i][j] == 'X') {
                continue;
            }
            int g = 0;
            g ^= calc_grundy(y1, x1, i, j, v);
            g ^= calc_grundy(i+1, x1, y2, j, v);
            g ^= calc_grundy(y1, j+1, i, x2, v);
            g ^= calc_grundy(i+1, j+1, y2, x2, v);
            s.insert(g);
        }
    }
    r = 0;
    while(s.count(r) == 1) {
        r++;
    }
    return r;
}

string solve(vector<string> const& v) {
    const int H = v.size();
    const int W = v[0].size();
    return calc_grundy(0, 0, H, W, v) == 0 ? "Second" : "First";
}

int main() {
    int H, W;
    cin >> H >> W;
    for(int i=0; i<21; ++i) {
        for(int j=0; j<21; ++j) {
            for(int k=0; k<21; ++k) {
                for(int l=0; l<21; ++l) {
                    grundy[i][j][k][l] = -1;
                }
            }
        }
    }
    vector<string> v(H);
    for(int i=0; i<H; ++i) {
        cin >> v[i];
    }
    cout << solve(v) << endl;
}
