inline void restore(int c){ /// hash = 804101
        for (int i = U[c]; i != c; i = U[i]){
            for (int j = L[i]; j != i; j = L[j]){
                column_count[col[j]]++;
                U[D[j]] = j, D[U[j]] = j;
            }
        }

        L[R[c]] = c, R[L[c]] = c;
    }