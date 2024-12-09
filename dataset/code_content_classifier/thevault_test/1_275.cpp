inline int query(int idx, int a, int b, int l, int r, int k){ /// hash = 476541
    int p = idx << 1, q = p | 1;
    int c = (a + b) >> 1, d = c + 1;

    if (a == l && b == r){
        if (tree[idx][0] > k) return 0;
        else return upper_bound(tree[idx].begin(), tree[idx].end(), k) - tree[idx].begin();
    }
    if (r <= c) return query(p, a, c, l, r, k);
    else if (l >= d) return query(q, d, b, l, r, k);
    else return query(p, a, c, l, c, k) + query(q, d, b, d, r, k);
}