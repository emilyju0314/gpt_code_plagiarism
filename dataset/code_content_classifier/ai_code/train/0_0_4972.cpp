#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<int> tree[100005];
int colors[100005];
long long blackCnt = 0;
long long ans = 1;

long long dfs(int node, int parent) {
    long long subtreeBlack = 0;
    for(int i=0;i<tree[node].size();i++) {
        int child = tree[node][i];
        if(child == parent) continue;
        long long childBlack = dfs(child, node);
        subtreeBlack += childBlack;
    }
    if(colors[node] == 1) {
        blackCnt++;
        return subtreeBlack + 1;
    }
    return subtreeBlack;
}

int main() {
    int n;
    cin >> n;

    for(int i=1;i<n;i++) {
        int parent;
        cin >> parent;
        tree[i].push_back(parent);
        tree[parent].push_back(i);
    }

    for(int i=0;i<n;i++) {
        cin >> colors[i];
    }

    dfs(0, -1);

    for(int i=0;i<n;i++) {
        if(colors[i] == 1) {
            ans = (ans * (blackCnt + 1)) % MOD;
        } else {
            ans = (ans * (blackCnt)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}