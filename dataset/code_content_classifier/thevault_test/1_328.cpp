bool satisfy(vector <int>& res){
        build();
        clr(visited);

        for (int i = 1; i <= m; i++){
            int x = order[i];
            if (parent[x] == parent[neg(x)]) return false;

            if (!visited[parent[x]]){
                visited[parent[x]] = true;
                visited[parent[neg(x)]] = false;
            }
        }

        res.clear();
        for (int i = 1; i <= n; i++){
            if (visited[parent[i]]) res.push_back(i);
        }
        return true;
    }