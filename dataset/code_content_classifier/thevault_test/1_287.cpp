Matrix(int n, int m, int diagonal = 0){
        clr(ar);
        row = n, col = m;
        for (int i = min(n, m) - 1; i >= 0; i--) ar[i][i] = diagonal;
    }