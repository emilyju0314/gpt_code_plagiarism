int func(int node, int prev, int pr, int nx, int si) {
    if (tree[node].size() == 1 && prev != -1) {
        if (pr == 1) {
            return 0;
        } else {
            return 0;
        }
    } else {
        int& ans = dp[node][pr][uc][nx][hs];
		
        if (ans == -1) {
            ans = INF;
            
            //use soldier
            int us = D;
            for (int i = 0; i < (int) tree[node].size(); i++) {
                int u = tree[node][i];
                
                us += func(u, node, 1, 1, 1, 0);
            }             
            chmin(ans, us);

            
            if (hs) {
                ans = D;
                
                for (int i = 0; i < (int) tree[node].size(); i++) {
                    int u = tree[node][i];

                    ans += func(u, node, 1, 1, 1, 0);
                }             
            } else {            
                int use_d = D;
                
                for (int i = 0; i < (int) tree[node].size(); i++) {
                    int u = tree[node][i];
                    
                    use_d += func(u, node, 1, 1, 1);
                }

            }
            chmin(ans, use_d);

            if (uc) {
                
            }
        }
        
        return ans;
    }
}