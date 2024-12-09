bool gauss(int n, double ar[MAX][MAX], double* R){
    int i, j, k, r;

    for (i = 0; i < n; i++){
        r = i;
        for (j = i + 1; j < n; j++){
            if (abs(ar[j][i]) > abs(ar[r][i])) r = j;
        }
        if (abs(ar[r][i]) < 1e-9) return false; /// No unique solution exists, set EPS carefully

        for (j = 0; j <= n && r != i; j++) swap(ar[i][j], ar[r][j]);
        for (k = i + 1; k < n; k++){
            double x = ar[k][i] / ar[i][i];
            for (j = i; j <= n; j++){
                ar[k][j] -= (x * ar[i][j]);
            }
        }
    }

    for (i = n - 1; i >= 0; i--){
        for (j = i + 1; j < n; j++){
            ar[i][n] -= (ar[j][n] * ar[i][j]);
        }
        ar[i][n] /= ar[i][i];
        R[i] = ar[i][n];
    }

    return true;
}