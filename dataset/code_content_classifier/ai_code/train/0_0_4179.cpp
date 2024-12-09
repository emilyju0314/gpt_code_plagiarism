#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findRoot(vector<int>& parent, int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findRoot(parent, parent[node]);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> parent(n);
    unordered_map<int, int> min_xor;

    for(int i = 0; i < n; i++) {
        parent[i] = i;
        min_xor[a[i]] = i;
    }

    int removals = 0;
    for(int i = n-1; i >= 0; i--) {
        int current = a[i];
        for(int j = 0; j < 32; j++) {
            int next = current ^ (1 << j);
            if(min_xor.find(next) != min_xor.end()) {
                int root1 = findRoot(parent, i);
                int root2 = findRoot(parent, min_xor[next]);
                if(root1 != root2) {
                    parent[root1] = parent[root2];
                } else {
                    removals++;
                }
            }
        }
    }

    cout << removals << endl;

    return 0;
}