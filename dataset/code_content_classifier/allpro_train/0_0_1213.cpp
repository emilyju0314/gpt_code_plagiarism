#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxN = 100001;
int parent[maxN];
int marked[maxN];

int find(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = find(parent[node]);
}

int main() {
    int N, Q;
    while (cin >> N >> Q && N != 0 && Q != 0) {
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            marked[i] = 0;
        }

        for (int i = 2; i <= N; i++) {
            int pi;
            cin >> pi;
            parent[i] = pi;
        }

        int sum = 0;
        for (int i = 0; i < Q; i++) {
            char op;
            int v;
            cin >> op >> v;
            if (op == 'M') {
                marked[v] = 1;
            } else {
                int ancestor = find(v);
                while (ancestor != 1 && !marked[ancestor]) {
                    ancestor = find(parent[ancestor]);
                }
                sum += ancestor;
            }
        }

        cout << sum << endl;
    }

    return 0;
}