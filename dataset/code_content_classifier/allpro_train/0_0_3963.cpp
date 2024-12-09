#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<pair<long long, long long>> s;
    long long offset = 0;

    for(int i = 0; i < Q; i++) {
        int query_type;
        cin >> query_type;

        if(query_type == 1) {
            long long a, b;
            cin >> a >> b;
            s.insert({a + offset, b - a});

        } else {
            auto it = s.begin();
            long long a = it->first;
            long long b = it->second;
            cout << a << " " << b + offset << endl;
        }
    }

    return 0;
}