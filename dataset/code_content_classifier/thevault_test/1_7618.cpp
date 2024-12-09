long long func(int node, int prev, int c_prev, int c_next) {
    if (tree[node].size() == 1 && prev != node) {
        if (c_prev == 0) {
            return D;
        } else if (c_prev == 1) {
            return min(C, D);
        } else {
            return 0;
        }
    } else {
        long long& ans = dp[node][c_prev][c_next];

        if (ans == -1LL) {
            ans = INF;

            long long child_sum_using_0 = 0;
            long long child_sum_using_c = C;
            long long child_sum_using_d = D;

            int using_0_c_prev = 0;
            int using_0_c_next = 0;

            if (c_prev == 2) {
                if (c_next == 0) {
                    using_0_c_prev = 1;
                } else {
                    using_0_c_prev = 2;
                }
            } else {
                using_0_c_prev = 0;
            }

            for (int i = 0; i < tree[node].size(); i++) {
                int next = tree[node][i];

                if (next == prev) {
                    continue;
                }

                if (c_prev > 0) {
                    child_sum_using_0 += func(next, node, using_0_c_prev, using_0_c_next);
                    child_sum_using_c += func(next, node, 2, 0);
                }
                child_sum_using_d += func(next, node, 2, 1);
            }

            if (c_prev > 0) {
                ans = min(ans, child_sum_using_0);
                ans = min(ans, child_sum_using_c);
            }

            ans = min(ans, child_sum_using_d);

            //cout << node << " " << c_prev << " " << c_next << " = " << child_sum_using_0 << " " << child_sum_using_c << " " << child_sum_using_d << "\n";
        }

        return ans;
    }
}