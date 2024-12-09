int bfs() {
    int ret = 0;
    queue<int> q;
    memset(v, 0, sizeof(v));
    FOR(i, 0, N) {
        u[i] = 0;
        pre[i] = -2;
        if (L[i] == -1) {
            q.push(i);
            pre[i] = -1;
        }
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        FOR(i, 0, edges[f].size()) {
            int next = edges[f][i];
            if (R[next] == -1) {
                int tf = f, tnext = next, m = 0;
                while (tf >= 0 && !m) {
                    m |= u[tf] | v[tnext];
                    u[tf] = v[tnext] = 1;
                    tnext = L[tf];
                    tf = pre[tf];
                }
                if (m) continue;
                while (f >= 0) {
                    R[next] = f;
                    tnext = next;
                    next = L[f];
                    L[f] = tnext;
                    f = pre[f];
                }
                ret++;
            } else {
                int ol = R[next];
                if (pre[ol] == -2) {
                    q.push(ol);
                    pre[ol] = f;
                }
            }
        }
    }
    return ret;
}