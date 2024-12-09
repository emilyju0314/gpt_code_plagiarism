inline int query(int l, int r){
        int c, d, x = (l / lg) + 1, y = (r / lg) - 1, res = l;

        if(x <= y){
            d = lg - mask[y - x + 1] - 1;
            res = op(res, op(dp[d][x], dp[d][y - (1 << d) + 1]));
        }

        c = x * lg, d = y * lg;
        res = op(res, mask[T[(c - 1) < r ? (c - 1) : r] & (~(((1 << (l - c + lg )) - 1) << (c - l)))] + c - lg);
        l = l > (d + lg) ? l : d + lg;
        res = op(res, mask[T[r] & (~(((1 << (l - d - lg)) - 1) << (d + (lg << 1) - l)))] + d + lg);
        return ar[res]; /// return res to return index of the minimum value(as op is set to min)
    }