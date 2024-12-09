void update_tree(int u, int l, int w){
        while (height[u] > height[l]){
            if (num[u]){
                int v = jump(u);
                if (height[v] <= height[l]) v = down[l];
                update_rmq(1, 1, id, num[v], num[u], w);
                u = parent[v];
            }
            else nodeval[u] = OPT(nodeval[u], w), u = parent[u]; /// Change here if set instead of add
        }
    }