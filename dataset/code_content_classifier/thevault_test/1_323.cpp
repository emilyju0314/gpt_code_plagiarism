inline void addrow(int r, vector <int>& columns){ /// hash = 438353
        int i, c, l = columns.size(), first = idx;

        for (i = 0; i < l; i++){
            c = columns[i];
            L[idx] = idx - 1, R[idx] = idx + 1, D[idx] = c, U[idx] = U[c];
            D[U[c]] = idx, U[c] = idx, row[idx] = r, col[idx] = c;
            column_count[c]++, idx++; /// column_count[c] is the number of rows which satisfies constraint column c
        }
        R[idx - 1] = first, L[first] = idx - 1;
    }