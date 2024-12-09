inline void remove(int c){ /// hash = 377852
        L[R[c]] = L[c], R[L[c]] = R[c];

        for (int i = D[c]; i != c; i = D[i]){
            for (int j = R[i]; j != i; j = R[j]){
                column_count[col[j]]--;
                U[D[j]] = U[j], D[U[j]] = D[j];
            }
        }
    }