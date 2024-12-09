bool algorithmX(int depth){ /// hash = 308201
        if(R[0] == 0){
            len = depth;
            return true;
        }

        int i, j, c = R[0];
        for (i = R[0]; i != 0; i = R[i]){ /// Select a column deterministically
            if(column_count[i] < column_count[c]) c = i; /// if multiple columns exist, choose the one with minimum count
        }

        remove(c);
        bool flag = false;
        for (i = D[c]; i != c && !flag; i = D[i]){ /// While solution is not found
            selected_rows[depth] = row[i];
            for (j = R[i]; j != i; j = R[j]) remove(col[j]);
            flag |= algorithmX(depth + 1); /// May be select rows non-deterministically here with random_shuffle?
            for (j = L[i]; j != i; j = L[j]) restore(col[j]);
        }

        restore(c);
        return flag;
    }