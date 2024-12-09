#include <bits/stdc++.h>
using namespace std;
using PLL = pair<int, int>;
template <typename T> using V = vector<T>;

V<V<int>> edges;
V<V<int>> ans;
V<PLL> pos;
set<int> outside;
V<int> next_nodes;
    
int N;

int dh[] = { 1, 0, -1, 0 };
int dw[] = { 0, 1, 0, -1 };

bool check_pos(int h, int w) {
    return 0 <= h && h < N &&
           0 <= w && w < N;
}

bool check_outside(int h, int w) {
    return check_pos(h, w) &&
           ((h == 0 || h == N - 1) ||
            (w == 0 || w == N - 1)); 
}

bool check_used(int h, int w) { return ans[h][w] != 0; }
bool check_used(int num) { return pos[num] != PLL(-1, -1); }

void calc_outside(int num, int h, int w) {
    ans[h][w] = num;
    pos[num] = PLL(h, w);
    next_nodes.push_back(num);
    int nxt_num = -1;
    for(int nxt : edges[num]) {
        if(check_used(nxt)) continue;
        if(outside.find(nxt) == outside.end()) continue;
        nxt_num = nxt;
        break;
    }
    if(nxt_num == -1) return;
    for(int i = 0; i < 4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(!check_outside(nh, nw) || check_used(nh, nw)) continue;
        calc_outside(nxt_num, nh, nw);
        break;
    }
}

void calc_inside() {
    V<int> next_next_nodes;
    for(int num : next_nodes) {
        int nxt_cand = -1;
        for(int nxt : edges[num]) {
            if(check_used(nxt)) continue;
            nxt_cand = nxt;
            break;
        }
        if(nxt_cand == -1) continue;
        int h, w;
        tie(h, w) = pos[num];
        for(int i = 0; i < 4; i++) {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(!check_pos(nh, nw) || check_used(nh, nw)) continue;
            next_next_nodes.push_back(nxt_cand);
            pos[nxt_cand] = PLL(nh, nw);
            ans[nh][nw] = nxt_cand;
            break;
        }
    }
    next_nodes = move(next_next_nodes);
}

int main() {
    cin >> N;
    int pow2 = N * N + 1;
    edges.resize(pow2);
    pos.resize(pow2, PLL(-1, -1));
    ans.resize(N, V<int>(N, 0));
    ans = V<V<int>>(N, V<int>(N, 0));
    for(int i = 0; i < 2 * N * N - 2 * N; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int init;
    for(int i = 1; i <= N * N; i++) if(edges[i].size() <= 3) {
        outside.insert(i);
        if(edges[i].size() == 2) init = i;
    }

    calc_outside(init, 0, 0);
    while(next_nodes.size()) calc_inside();

    for(auto &&ele : ans) for(int i = 0; i < N; i++) cout << ele[i] << " \n"[i + 1 == N];
    return 0;
}

