#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    list<int> lst;
    auto itr = lst.end();
    int x, d;
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        switch (query) {
            case 0:
                cin >> x;
                itr = lst.insert(itr, x);
                break;
            case 1:
                cin >> d;
                for (int i = 0; i < abs(d); ++i) (d > 0 ? itr++ : itr--);
                break;
            case 2:
                itr = lst.erase(itr);
                break;
        }
    }
    for (auto a : lst) cout << a << endl;
    return 0;
}


