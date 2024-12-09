#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), cnt(n, 0);
    for (auto& x : xs) {
        std::cin >> x;
        ++cnt[--x];
    }

    std::set<int> ss;
    for (int x = 0; x < n; ++x) ss.insert(x);

    std::vector<int> ans;
    ans.reserve(n);

    int out = -1;
    while (ss.size() > 6) {
        int x = *ss.begin();
        if (x == out) {
            if (ss.size() == 1) {
                std::cout << -1 << std::endl;
                return;
            } else {
                x = *(++ss.begin());
            }
        }

        int k = ss.size();
        int y = xs[x];
        if (ss.count(y) && cnt[y] == k - 1) x = y;

        ss.erase(x);
        ans.push_back(x);
        --cnt[xs[x]];
        out = xs[x];
    }

    std::vector<int> rem(ss.begin(), ss.end());
    do {
        auto tmpans = ans;
        for (auto x : rem) ans.push_back(x);

        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if (ans[i + 1] == xs[ans[i]]) ok = false;
        }

        if (ok) {
            for (auto x : ans) std::cout << x + 1 << " ";
            std::cout << std::endl;
            return;
        }

        ans = tmpans;
    } while (std::next_permutation(rem.begin(), rem.end()));
    std::cout << -1 << std::endl;
}

int main() {
    // int q;
    // std::cin >> q;
    // while (q--) solve();
    solve();
    return 0;
}
