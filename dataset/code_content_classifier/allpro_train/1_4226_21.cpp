#include <bits/stdc++.h>
using namespace std;
using Int = long long;
struct SegTreeMax {
    vector<Int> A;
    int N;
    SegTreeMax(int n) {
        N = 1;
        while (N < n) N *= 2;
        A.resize(2*N, LONG_LONG_MIN);
    }
    void set(int i, Int val) {
        i += N;
        A[i] = val;
        i /= 2;
        while (i > 0) {
            A[i] = max(A[2*i+0], A[2*i+1]);
            i /= 2;
        }
    }
    Int query(int L, int R) {
        L += N, R += N;
        Int ans = LONG_LONG_MIN;
        while (L < R) {
            if (R & 1) ans = max(ans, A[--R]);
            if (L & 1) ans = max(ans, A[L++]);
            L /= 2, R /= 2;
        }
        return ans;
    }
};
int main()
{
    int N; cin >> N;
    vector<Int> X(N), S(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> S[i];
    vector<Int> sum(N+1);
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + S[i];
    SegTreeMax st(N+1);
    st.set(0, 0);
    for (int i = 0; i < N; i++) st.set(i+1, sum[i+1] - X[i]);
    Int ans = 0;
    for (int i = 0; i < N; i++) {
        Int score = st.query(i+1, N+1) - st.query(i, i+1) + X[i] - (i > 0 ? X[i-1] : 0);
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}