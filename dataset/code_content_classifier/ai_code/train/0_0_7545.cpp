#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void merge(int x, int y, vector<int>& parent, vector<int>& size) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> parent(n);
    vector<int> size(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    unordered_map<int, int> last_seen;
    int components = n;

    for (int i = 0; i < n; i++) {
        if (last_seen.find(a[i]) != last_seen.end()) {
            merge(i, last_seen[a[i]], parent, size);
            components--;
        }
        last_seen[a[i]] = i;
    }

    cout << components << endl;

    for (int j = 0; j < q; j++) {
        int pos, x;
        cin >> pos >> x;
        pos--;

        if (pos > 0 && a[pos - 1] < a[pos]) {
            merge(pos - 1, pos, parent, size);
            components--;
        }

        if (pos < n - 1 && a[pos] < a[pos + 1]) {
            merge(pos, pos + 1, parent, size);
            components--;
        }

        if (last_seen.find(a[pos]) != last_seen.end()) {
            merge(last_seen[a[pos]], pos, parent, size);
            components++;
        }
        last_seen[a[pos]] = pos;

        a[pos] = x;

        cout << components << endl;
    }

    return 0;
}