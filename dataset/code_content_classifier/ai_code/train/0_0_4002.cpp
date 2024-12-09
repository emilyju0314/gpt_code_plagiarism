#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    multiset<int> s;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }

    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < q; ++i) {
        if (queries[i] > 0) {
            s.insert(queries[i]);
        } else {
            auto it = s.begin();
            advance(it, abs(queries[i])-1);
            s.erase(it);
        }
    }

    if (s.empty()) {
        cout << "0\n";
    } else {
        cout << *(s.begin()) << "\n";
    }

    return 0;
}