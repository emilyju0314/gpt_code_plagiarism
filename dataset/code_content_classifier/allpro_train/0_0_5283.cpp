#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    set<int> S;
    
    for(int i=0; i<q; i++) {
        int query, x, L, R;
        cin >> query;
        
        if(query == 0) {
            cin >> x;
            S.insert(x);
            cout << S.size() << endl;
        } else if(query == 1) {
            cin >> x;
            cout << S.count(x) << endl;
        } else if(query == 2) {
            cin >> x;
            S.erase(x);
        } else if(query == 3) {
            cin >> L >> R;
            auto it = S.lower_bound(L);
            while(it != S.end() && *it <= R) {
                cout << *it << endl;
                it++;
            }
        }
    }
    
    return 0;
}