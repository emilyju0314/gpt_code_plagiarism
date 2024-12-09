#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

vector<int> parent;
vector<int> value;
vector<vector<int>> children;
vector<long long> power;

int getPower(int u) {
    if(children[u].empty()) {
        return value[u];
    }
    long long sum = value[u];
    for(int child : children[u]) {
        sum += getPower(child);
    }
    return (sum * (children[u].size())) % MOD;
}

int main() {
    int v1, q;
    cin >> v1 >> q;

    parent.push_back(-1);
    value.push_back(v1);
    children.push_back({});
    power.push_back(v1);

    unordered_map<int, int> indices;
    indices[1] = 0;

    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int p, v;
            cin >> p >> v;
            p--;

            parent.push_back(p);
            value.push_back(v);
            children.push_back({});
            power.push_back(0);

            children[p].push_back(i+1);
            indices[i+2] = i+1;
        } else {
            int u;
            cin >> u;
            u--;

            int result = getPower(indices[u]);
            cout << result << endl;
        }
    }

    return 0;
}