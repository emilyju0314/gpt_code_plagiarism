#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MOD = 1000000007;

vector<int> parent;
vector<int> rank;

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        parent.resize(N+1);
        rank.assign(N+1, 0);
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        unordered_set<int> lightAttributes;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            lightAttributes.insert(a);
            lightAttributes.insert(b);
            union_sets(a, b);
        }

        unordered_set<int> rootAttributes;
        for (int i = 1; i <= N; i++) {
            rootAttributes.insert(find(i));
        }

        long long result = 1;
        for (int attribute : rootAttributes) {
            if (lightAttributes.find(attribute) == lightAttributes.end()) {
                result = (result * 2) % MOD;
            }
        }

        cout << result << endl;
    }

    return 0;
}