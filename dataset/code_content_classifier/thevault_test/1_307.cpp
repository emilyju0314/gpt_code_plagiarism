inline int binomial(long long n, long long k){
        if (k > n) return 0;

        int res = 1;
        while (k){
            res = ((long long)res * count(n % MOD, k % MOD)) % MOD;
            n /= MOD, k /= MOD;
        }
        return res;
    }