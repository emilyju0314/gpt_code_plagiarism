bool Pairsum(vector <int> ar, vector <int>& res){
    res.clear();
    sort(ar.begin(), ar.end());
    int i, j, k, l, a, b, x, n = ar.size();

    if (n == 0){
        res.push_back(1);
        return true;
    }
    if (n == 1){
        if (ar[0] < 2) return false;
        res.push_back(1), res.push_back(ar[0] - 1);
        return true;
    }

    res.resize(n, 0);
    a = ar[0], b = ar[1];
    for (i = 2, k = 2; i * (i - 1) < 2 * n && k < n; i++, k++){
        if ((a + b - ar[k]) & 1 ^ 1){
            j = 1, res[0] = (a + b - ar[k]) >> 1;
            multiset <int> S(ar.begin(), ar.end());

            while (S.size()){
                res[j] = *S.begin() - res[0];
                for (l = 0; l < j && !S.empty(); l++){
                    auto pos = S.find(res[l] + res[j]);
                    if (pos == S.end()) goto skip;
                    S.erase(pos);
                }
                j++;
            }

            skip:
            if (j * (j - 1) == 2 * n){
                res.resize(j);
                sort(res.begin(), res.end());
                return true;
            }
        }
    }
    return false;
}