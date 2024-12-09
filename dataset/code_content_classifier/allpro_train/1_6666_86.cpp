#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;
typedef pair<int, int> P;
typedef pair< int, vector<int> > Q;

#define MAX 100005
#define INF 1001001001

int main(int, char**)
{
    vector<int> b(9);
    rep(i,9) { cin >> b[i]; b[i]--; }

    map< vector<int>, bool > close;
    map< vector<int>, int > h;
    priority_queue< Q, vector<Q>, greater<Q> > q;

    auto heu = [&](vector<int> v) -> int {
        if (h.count(v)) return h[v];
        int dif = 0;
        rep(i,9) {
            if (v[i] == -1) continue;
            dif += abs(v[i]/3 - i/3) + abs(v[i]%3 - i%3); // 各パネルの目的地までのマンハッタン距離の総和
        }
        h[v] = dif;
        return dif;
    };

    q.push({heu(b), b});
    int ans;
    while (!q.empty()) {
        vector<int> b;
        int f;
        tie(f,b) = q.top(); q.pop();
        if (h[b]==0) {
            ans = f;
            break;
        }
        close[b] = true;
 
        int g = f - h[b];

        int r, c;
        rep(i,9) {
            if (b[i] == -1) {
                r = i/3;
                c = i%3;
                break;
            }
        }
        int dr[4] = { -1,  0,  1,  0};
        int dc[4] = {  0, -1,  0,  1};
        rep(i,4) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;
            vector<int> nb = b;
            swap(nb[nr*3+nc], nb[r*3+c]);
            if (!close[nb]) {
                q.push({g+1+heu(nb), nb});
            }
        }
    }
    cout << ans << endl;

    return 0;
}

