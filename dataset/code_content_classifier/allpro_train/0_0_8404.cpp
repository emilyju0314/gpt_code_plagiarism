#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> S;
    map<int, int> count;

    for(int i = 0; i < q; i++) {
        int op, x;
        cin >> op >> x;

        if(op == 0) {
            S.insert(x);
            cout << S.size() << endl;
        } else if(op == 1) {
            cout << count[x] << endl;
        } else {
            if(S.find(x) != S.end()) {
                S.erase(x);
            }
        }
    }

    return 0;
}