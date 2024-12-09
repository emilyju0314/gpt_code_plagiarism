inline void push(int idx, int a, int b){
        int c = (a + b) >> 1, d = c + 1, p = idx << 1, q = p | 1;
        if (lazy[idx]){
            tree[idx] += (lazy[idx] * (b - a + 1)); /// Change lazy according to operation
            if (a != b) lazy[p] += lazy[idx], lazy[q] += lazy[idx]; /// Change lazy according to operation
            lazy[idx] = 0;
        }
    }