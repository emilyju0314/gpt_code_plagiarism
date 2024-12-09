void reconstruct(int i, int j, const string &a, const string &b, string &ans) {
    if (i < 0 || j < 0) return;
    if (a[i] == b[j]) {
        ans += a[i];
        return reconstruct(i - 1, j - 1, a, b, ans);
    }
    if ((i ? dp[i - 1][j] : 0) > (j ? dp[i][j - 1] : 0))
        return reconstruct(i - 1, j, a, b, ans);
    reconstruct(i, j - 1, a, b, ans);
}