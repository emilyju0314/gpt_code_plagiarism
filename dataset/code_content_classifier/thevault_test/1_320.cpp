long long interpolate(vector <int>& recurrence, long long n){ /// hash = 377697
        int len = recurrence.size();
        if (n < len) return recurrence[n];

        vector <int> polynomial;
        int l = berlekamp_massey(recurrence, polynomial);
        while (l && polynomial[l] == 0){
            l--;
            polynomial.pop_back();
        }
        reverse(polynomial.begin(), polynomial.begin() + l + 1);

        struct Matrix mat = Matrix(l);
        for (int i = 1; i < mat.n; i++) mat.ar[i][i - 1] = 1;
        for (int i = 0; i < mat.n; i++) mat.ar[0][i] = MOD - polynomial[l - i - 1];

        long long res = 0;
        mat = mat ^ (n - len + 1);
        for (int i = 0; i < mat.n; i++) res = (res + (long long)mat.ar[0][i] * recurrence[len - i - 1]) % MOD;
        return res;
    }