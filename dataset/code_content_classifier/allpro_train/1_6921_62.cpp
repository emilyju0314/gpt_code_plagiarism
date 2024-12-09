#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))
#define ALL(a) (a.begin(), a.end())
typedef vector<int> vi;

constexpr int INF = 1000000000;

int main() {
    int h,w;
    cin>>h>>w;
    vector<string> t(h);
    int pi, pj, hi, hj;
    vi si, sj;
    REP(i,h) {
        cin>>t[i];
        REP(j,w) {
            switch (t[i][j]) {
                case '@':
                pi = i;
                pj = j;
                break;
                case '%':
                hi = i;
                hj = j;
                break;
                case '$':
                si.push_back(i);
                sj.push_back(j);
            }
        }
    }
    vector<vi> dist(h, vi(w, INF));
    dist[hi][hj] = 0;
    queue<pair<int,int>> que;
    que.push(make_pair(hi, hj));
    while(!que.empty()) {
        int i, j;
        tie(i,j) = que.front();
        que.pop();
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        REP(k,4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (t[ni][nj] == '#') continue;
            if (dist[ni][nj] <= dist[i][j] + 1) continue;
            dist[ni][nj] = dist[i][j] + 1;
            que.push(make_pair(ni, nj));
        }
    }
    int pd = dist[pi][pj];
    bool valid = true;
    REP(i, si.size()) {
        if (dist[si[i]][sj[i]] <= pd) {
            valid = false;
        }
    }
    if (valid) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}