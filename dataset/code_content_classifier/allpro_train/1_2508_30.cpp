#include <iostream>
#include <vector>
 
template<class T>
using Graph = std::vector<std::vector<T>>;
 
bool dfs(Graph<int> &G, int step, int u, int v,
         std::vector<bool> &visited)
{
    int n = G.size();
    int x = (step < n / 2 ? u : v);
    if (step == n - 1) {
        return true;
    }
     
    bool ret = false;
    for (int next : G[x]) {
        if (!visited[next]) {
            visited[next] = true;
 
            if (step < n / 2) {
                ret |= dfs(G, step + 1, next, v, visited);
            } else {
                ret |= dfs(G, step + 1, u, next, visited);
            }           
        }        
    }
 
    return ret;
}
 
bool solve(Graph<int> &G, int u, int v)
{
    int n = G.size();
    if (n & 1) {
        return false;
    }
 
    std::vector<bool> visited(n, false);
    visited[u] = visited[v] = true;
    return dfs(G, 1, u, v, visited);
}
 
int main()
{
    int n, u, v;
    std::cin >> n >> u >> v;
    u--; v--;
     
    Graph<int> G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
 
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
 
    std::cout << (solve(G, u, v) ? "Yes" : "No") << std::endl;
     
    return 0;
}