void init(int m, int* val){
        int i, j, k, d, top;
        for (n = 0; n < m; n++) ar[n] = val[n];

        lg = 32 - __builtin_clz(n);
        d = -1, i = 0, len = (n + lg - 1) / lg;

        while (i < n){
            dp[0][++d] = i++;
            for (j = 1; j < lg && i < n; i++, j++){
                dp[0][d] = op(i, dp[0][d]);
            }
        }

        for (j = 1; j < lg; j++){
            d = (1 << j) >> 1;
            for (i = 0; i < len; i++){
                dp[j][i] = op(dp[j - 1][i], dp[j - 1][i + ((i + d) < len ? d : 0)]);
            }
        }

        for (i = 0; i < len; i++){
            top = 0, d = (i * lg) + lg;
            for (j = d - lg; j < n && j < d; j++){
                while (top && ar[j] < ar[mask[top]]) top--; /// Change to ar[j] > ar[mask[top]] for max
                T[j] = 1 << (d - j - 1);
                if (top) T[j] |= T[mask[top]];
                mask[++top] = j;
            }
        }

        for (i = 1, k = 1 << lg, d = lg - 1; i < k; i++){
            if (i >= (1 << (lg - d))) d--;
            mask[i] = d;
        }
    }