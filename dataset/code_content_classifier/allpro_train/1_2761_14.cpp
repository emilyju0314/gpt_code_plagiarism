#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


struct LowLink{
    vector<vector<int>>& edges;
    // 関節点
    vector<int> art;
    vector<pair<int,int>> bridge;

    vector<int> ord, low;
    int k;

    void dfs(int idx, int par){
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_art = false;
        int cnt = 0;
        for(auto& to : edges[idx]){
            if(ord[to] == -1){
                ++cnt;
                dfs(to, idx);
                low[idx] = min(low[idx], low[to]);
                is_art |= par != -1 && low[to] >= ord[idx];
                if(ord[idx] < low[to])
                    bridge.emplace_back(idx, to);
            }else if(to != par)
                low[idx] = min(low[idx], ord[to]);
        }
        is_art |= (par == -1 && cnt > 1);
        if(is_art)
            art.emplace_back(idx);
    }

    LowLink(vector<vector<int>>& edges) :
        edges(edges),
        ord(edges.size(), -1),
        low(edges.size(), 0),
        k(0)
    {
        for(int i = 0; i < edges.size(); ++i)
            if(ord[i] == -1)
                dfs(i, -1);
        for(auto& b : bridge)
            b = minmax(b.first, b.second);
        sort(art.begin(), art.end());
        sort(bridge.begin(), bridge.end());
    }
};


struct Result{
    int group_cnt;
    vector<int> group;
    vector<vector<int>> group_elm_list;
    // 同じ二重辺連結成分の辺をグループごとに列挙する, 片方向のみ(辺数倍化しない)
    vector<vector<pair<int,int>>> same_group_edges;
    // 橋, 片方向のみ
    vector<pair<int,int>> bridges;
    // 関節点
    vector<int> arts;
    vector<vector<int>> tree_graph;
    vector<int> par;
    vector<vector<int>> childs;
};

Result two_edge_connected_components_tree(vector<vector<int>>& edges){
    int n = edges.size();
    LowLink ll(edges);
    vector<vector<int>> not_bridge_graph(n);
    for(int i = 0; i < n; ++i)
        for(auto j : edges[i]){
            pair<int,int> min_max = minmax(i, j);
            auto iter = lower_bound(ll.bridge.begin(), ll.bridge.end(), min_max);
            if(iter == ll.bridge.end() || *iter != min_max)
                not_bridge_graph[i].push_back(j);
        }

    vector<int> group(n, -1);
    function<void(int)> group_dfs = [&](int x){
        for(auto y : not_bridge_graph[x])
            if(group[y] == -1){
                group[y] = group[x];
                group_dfs(y);
            }
    };
    int group_cnt = 0;
    for(int i = 0; i < n; ++i)
        if(group[i] == -1){
            group[i] = group_cnt++;
            group_dfs(i);
        }
    vector<vector<int>> group_elm_list(group_cnt);
    for(int i = 0; i < n; ++i)
        group_elm_list[group[i]].push_back(i);

    vector<vector<pair<int,int>>> same_group_edges(group_cnt);
    vector<vector<int>> tree_edges(group_cnt);
    vector<int> par(group_cnt, -1);
    vector<vector<int>> childs(group_cnt);

    for(int i = 0; i < n; ++i)
        for(auto j : edges[i])
            if(group[i] == group[j] && i < j)
                same_group_edges[group[i]].emplace_back(i, j);

    for(auto& p : ll.bridge){
        tree_edges[group[p.first]].push_back(group[p.second]);
        tree_edges[group[p.second]].push_back(group[p.first]);
    }
    vector<bool> flag(n, false);
    function<void(int)> tree_dfs = [&](int x){
        for(auto y : tree_edges[x])
            if(!flag[y]){
                flag[y] = true;
                par[y] = x;
                childs[x].push_back(y);
                tree_dfs(y);
            }
    };
    flag[0] = true;
    tree_dfs(0);

    Result res;
    res.group_cnt = group_cnt;
    res.group_elm_list = move(group_elm_list);
    res.same_group_edges = move(same_group_edges);
    res.bridges = move(ll.bridge);
    res.arts = move(ll.art);
    res.group = move(group);
    res.tree_graph = move(tree_edges);
    res.par = move(par);
    res.childs = move(childs);
    return res;
}

struct BinaryLifting{
    int n;
    vector<vector<int>> next;
    vector<int> depth;

    BinaryLifting(vector<vector<int>>& edges, int root = 0) : n(edges.size()), depth(n, -1){
        vector<int> par(n, -1);
        function<void(int)> dfs = [&](int x){
            for(auto y : edges[x])
                if(depth[y] == -1){
                    depth[y] = depth[x] + 1;
                    par[y] = x;
                    dfs(y);
                }
        };
        depth[root] = 0;
        dfs(0);

        next.push_back(move(par));
        for(int k = 0;; ++k){
            bool fl = false;
            next.emplace_back(n, -1);
            for(int i = 0; i < n; ++i){
                next[k + 1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
                if(next[k + 1][i] != -1)
                    fl = true;
            }
            if(!fl)
                break;
        }
    }
    // kth_next(x, 0) => x
    int kth_next(int x, int k){
        for(int i = 0; i < next.size() && k; ++i){
            if(k & (1 << i)){
                x = next[i][x];
                if(x == -1)
                    break;
            }
        }
        return x;
    }

    int lca(int x, int y){
        int min_depth = min(depth[x], depth[y]);
        x = kth_next(x, depth[x] - min_depth);
        y = kth_next(y, depth[y] - min_depth);
        if(x == y)
            return x;
        for(int i = next.size() - 1; i >= 0; --i)
            if(next[i][x] != next[i][y]){
                x = next[i][x];
                y = next[i][y];
            }
        return next[0][x];
    }
};

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    int k;
    cin >> k;
    vector<int> u(k), v(k);
    for(int i = 0; i < k; ++i){
        cin >> u[i] >> v[i];
        --u[i], --v[i];
    }
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i){
        edges[a[i]].push_back(b[i]);
        edges[b[i]].push_back(a[i]);
    }

    Result res = two_edge_connected_components_tree(edges);
    BinaryLifting tree(res.tree_graph);

    vector<int> fl1(res.group_cnt, 0);
    vector<int> fl2(res.group_cnt, 0);
    for(int i = 0; i < k; ++i){
        int uu = res.group[u[i]];
        int vv = res.group[v[i]];
        int lca = tree.lca(uu, vv);
        ++fl1[uu];
        ++fl2[vv];
        --fl1[lca];
        --fl2[lca];
    }
    function<void(int)> df = [&](int x){
        for(auto& y : res.childs[x]){
            df(y);
            fl1[x] += fl1[y];
            fl2[x] += fl2[y];
        }
    };
    df(0);

    for(int i = 1; i < n; ++i)
        if(fl1[i] && fl2[i]){
            cout << "No" << endl;
            return 0;
        }

    map<pair<int,int>, int> edge_data;
    for(int i = 1; i < res.group_cnt; ++i){
        int j = tree.kth_next(i, 1);
        if(fl1[i])
            edge_data[minmax(i, j)] = 1;
        else
            edge_data[minmax(i, j)] = 2;
    }

    map<pair<int,int>, int> edge_raw_data;

    for(int i = 0; i < res.group_cnt; ++i){
        vector<int>& elm_list = res.group_elm_list[i];
        vector<pair<int,int>>& edge_list = res.same_group_edges[i];
        int group_size = elm_list.size();
        vector<vector<int>> group_edges(group_size);
        for(auto& p : edge_list){
            int p1 = distance(elm_list.begin(), lower_bound(elm_list.begin(), elm_list.end(), p.first));
            int p2 = distance(elm_list.begin(), lower_bound(elm_list.begin(), elm_list.end(), p.second));
            group_edges[p1].emplace_back(p2);
            group_edges[p2].emplace_back(p1);
        }
        vector<bool> visited(group_size, false);
        function<void(int,int)> f = [&](int x, int prev){
            for(auto y : group_edges[x]){
                if(y == prev)
                    continue;
                if(!visited[y]){
                    auto p = minmax(elm_list[x], elm_list[y]);
                    edge_raw_data[minmax(elm_list[x], elm_list[y])] = 1;
                    visited[y] = true;
                    f(y, x);
                }
                else{
                    auto p = minmax(elm_list[x], elm_list[y]);
                    edge_raw_data[minmax(elm_list[x], elm_list[y])] = 2;
                }
            }
        };
        visited[0] = true;
        f(0, -1);
    }

    vector<int> ans(m, -1);
    for(int i = 0; i < m; ++i){
        if(res.group[a[i]] != res.group[b[i]])
            ans[i] = edge_data[minmax(res.group[a[i]], res.group[b[i]])];
        else
            ans[i] = edge_raw_data[minmax(a[i], b[i])];
    }
    cout << "Yes" << endl;
    for(int i = 0; i < m; ++i){
        if(ans[i] == 2)
            cout << a[i] + 1 << " " << b[i] + 1 << endl;
        else
            cout << b[i] + 1 << " " << a[i] + 1 << endl;
    }

    return 0;
}

