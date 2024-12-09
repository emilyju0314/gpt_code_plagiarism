string generate_text(int n, string &p) {
    string t;
    t.resize(n);
    vector<size_t> occ;

    int pos = -1;
    while (pos < n - (int)p.size()) {
        pos = rnd.next(pos + 1, n - (int)p.size());
        occ.push_back(pos);
        pos+=p.size();
    }
    for (size_t i = 0, j = 0; i < n;) {
        if (j<occ.size() && i == occ[j]) {
            for (size_t k = 0; k < p.size(); k++) {
                t[i + k] = p[k];
            }
            i+=p.size();
            j++;
        } else {
            t[i++] = rnd.any(alphabet);
        }
    }
    return t;
}