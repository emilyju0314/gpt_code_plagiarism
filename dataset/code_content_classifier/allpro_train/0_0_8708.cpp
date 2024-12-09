#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x], parent);
    }
}

void merge(int x, int y, vector<int>& parent) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        merge(i, p[i]-1, parent);
    }

    int trees = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            trees++;
        }
    }

    cout << trees << endl;

    return 0;
}