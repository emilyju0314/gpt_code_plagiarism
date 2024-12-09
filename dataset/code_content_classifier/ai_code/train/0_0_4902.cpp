#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void performShift(vector<int>& a, int li, int ri) {
    for (int i = ri; i > li; i--) {
        swap(a[i], a[i-1]);
    }
}

void reverseSegment(vector<int>& a, int li, int ri) {
    reverse(a.begin() + li - 1, a.begin() + ri);
}

int main() {
    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, pair<int, int>>> queries(q);
    for (int i = 0; i < q; i++) {
        int t, li, ri;
        cin >> t >> li >> ri;
        queries[i] = {t, {li, ri}};
    }

    vector<int> importantIndices(m);
    for (int i = 0; i < m; i++) {
        cin >> importantIndices[i];
    }

    // Perform queries
    for (int i = q - 1; i >= 0; i--) {
        int t = queries[i].first;
        int li = queries[i].second.first;
        int ri = queries[i].second.second;

        if (t == 1) {
            performShift(a, li-1, ri-1);
        } else {
            reverseSegment(a, li, ri);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << a[importantIndices[i]-1] << " ";
    }

    return 0;
}