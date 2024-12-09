#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<pair<int, int>>> adj;
int M;
long long count = 0;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void dfs(int u, int parent, int num, map<int, int> &freq){
    num = (num * 10 + adj[parent][u].second) % M;
    int g = gcd(num, M);
    
    if(g != 1){
        count += freq[M / g];
    }
    
    freq[num]++;
    
    for(auto neighbor : adj[u]){
        if(neighbor.first != parent){
            dfs(neighbor.first, u, num, freq);
        }
    }
    
    freq[num]--;
}

int main() {
    int n;
    cin >> n >> M;
    
    adj.resize(n);
    
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    map<int, int> freq;
    freq[0] = 1;
    
    for(auto neighbor : adj[0]){
        dfs(neighbor.first, 0, neighbor.second, freq);
    }
    
    cout << count << endl;
    
    return 0;
}