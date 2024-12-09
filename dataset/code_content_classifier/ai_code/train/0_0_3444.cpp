#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int v) {
    if(parent[v] == v) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[b] = a;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N+1);
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unionSets(a, b);
    }

    int components = 0;
    vector<int> sizes(N+1, 0);
    for(int i = 1; i <= N; i++) {
        sizes[find(i)]++;
    }

    for(int i = 1; i <= N; i++) {
        if(i != find(1) && i != find(2) && find(i) == i) {
            components++;
        }
    }

    long long ans = 1LL * components * (components - 1) / 2;
    for(int i = 1; i <= N; i++) {
        ans += 1LL * sizes[i] * (sizes[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}