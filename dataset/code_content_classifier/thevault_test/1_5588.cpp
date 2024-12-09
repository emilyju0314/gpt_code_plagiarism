string LCS(string a, string b) {
    FOR(i, 0, a.length()) {
        FOR(j, 0, b.length()) {
            dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
            if (a[i] == b[j]) dp[i][j] = (i && j ? dp[i - 1][j - 1] : 0) + 1;
        }
    }
    string ans = "";
    int i = a.length(), j = b.length();
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            ans += a[i];
            i--, j--;
        } else if ((i ? dp[i - 1][j] : 0) > (j ? dp[i][j - 1] : 0)) {
            i--;
        } else
            j--;
    }
    return ans;
}