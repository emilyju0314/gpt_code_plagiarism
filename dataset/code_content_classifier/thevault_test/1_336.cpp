void karatsuba(int n, int *a, int *b, int *res){ /// hash = 829512
        int i, j, h;
        if (n < 17){
            for (i = 0; i < (n + n); i++) temp[i] = 0;
            for (i = 0; i < n; i++){
                if (a[i]){
                    for (j = 0; j < n; j++){
                        temp[i + j] += ((long long)a[i] * b[j]);
                    }
                }
            }
            for (i = 0; i < (n + n); i++) res[i] = temp[i] % MOD;
            return;
        }

        h = n >> 1;
        karatsuba(h, a, b, res);
        karatsuba(h, a + h, b + h, res + n);
        int *x = buffer + ptr, *y = buffer + ptr + h, *z = buffer + ptr + h + h;

        ptr += (h + h + n);
        for (i = 0; i < h; i++){
            x[i] = a[i] + a[i + h], y[i] = b[i] + b[i + h];
            if (x[i] >= MOD) x[i] -= MOD;
            if (y[i] >= MOD) y[i] -= MOD;
        }

        karatsuba(h, x, y, z);
        for (i = 0; i < n; i++) z[i] -= (res[i] + res[i + n]);
        for (i = 0; i < n; i++){
            res[i + h] = (res[i + h] + z[i]) % MOD;
            if (res[i + h] < 0) res[i + h] += MOD;
        }
        ptr -= (h + h + n);
    }