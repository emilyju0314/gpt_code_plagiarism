#include <iostream>
#include <vector>

using namespace std;

char solve(int n, long long k) {
    if (n == 0) {
        if (k <= 34) {
            string str = "What are you doing at the end of the world? Are you busy? Will you save us?";
            return str[k - 1];
        } else {
            return '.';
        }
    }

    long long len = 34;
    long long mid = 32;
    long long end = 32;

    for (int i = 1; i <= n; i++) {
        long long new_len = 2*len + 68;
        if (k <= mid) {
            len = (len - 68) / 2;
            new_len = 2*len + 68;
            mid = len + 34;
            end = len + 35;
        } else if (k <= end) {
            return solve(n-1, k-len-1);
        } else if (k <= new_len) {
            k -= end;
        } else {
            return '.';
        }
    }

    return '.';
}

int main() {
    int q;
    cin >> q;

    vector<pair<int, long long>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (int i = 0; i < q; i++) {
        cout << solve(queries[i].first, queries[i].second);
    }

    cout << endl;

    return 0;
}