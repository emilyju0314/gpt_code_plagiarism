Polygon(int ni, struct Point* T, int flag){
        n = ni;
        for (int i = 0; i < n; i++){
            if (flag == CLOCKWISE) ar[i] = T[i];
            else ar[i] = T[n - i - 1];
        }
    }