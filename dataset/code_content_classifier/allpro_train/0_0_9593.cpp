#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int colors[MAXN];
vector<int> tree[MAXN];
long long ans[MAXN];

int dfs(int node, int parent, vector<int>& count) {
    int current_color = colors[node];
    count[current_color]++;
    
    int total_paths = count[current_color];
    for (int child : tree[node]) {
        if (child != parent) {
            total_paths += dfs(child, node, count);
        }
    }
    
    count[current_color]--;
    return ans[current_color] += total_paths;
}

int main() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> colors[i];
    }
    
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    vector<int> count(MAXN, 0);
    dfs(1, 0, count);
    
    for (int k = 1; k <= N; k++) {
        cout << ans[k] << endl;
    }
    
    return 0;
}