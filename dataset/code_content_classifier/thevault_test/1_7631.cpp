int query(int node, int l, int r, int bl, int br){
    if(l > br || r < bl || l > r){
        return 0;
    }else if(l >= bl && r <= br){
        //int greater = upper_bound(tree[node].begin(), tree[node].end(), br) - tree[node].begin();
        int greater = lower_search(tree[node], br+1);
        if(greater == INT_MAX){
            return 0;
        }else{
            return tree[node].size() - greater;
        }
    }else{
        int mid = (l+r) >> 1;
        int lq = query(node << 1, l, mid, bl, br);
        int rq = query((node << 1) | 1, mid+1, r, bl, br);
        return lq + rq;
    }
}