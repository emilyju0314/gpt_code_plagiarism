#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

vector<vector<int>> adj;
vector<int> color;
int count = 0;

int rnd() {
    return rand() % 2;
}

void paint(int s) {
    if (count % 2 == 0) {
        color[s] = 0;
    } else {
        color[s] = 1;
    }
    
    count++;
    
    vector<int> children;
    if (rnd() == 1) {
        children = adj[s];
        sort(children.begin(), children.end());
    } else {
        children = adj[s];
        sort(children.begin(), children.end(), greater<int>());
    }
    
    for (int child : children) {
        if (rnd() == 1) {
            paint(child);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    color.resize(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    paint(1);
    
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * 2) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}