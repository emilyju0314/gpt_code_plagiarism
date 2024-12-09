#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> parent(n);
    vector<int> count(n+1, 0);
    int root = -1;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
        parent[i] = a[i];
        if (a[i] == i + 1) {
            root = i + 1;
        }
    }

    if (root == -1) {
        for (int i = 0; i < n; i++) {
            if (count[i+1] == 0) {
                root = i + 1;
                parent[i] = i + 1;
                break;
            }
        }
    }

    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != i + 1) {
            parent[i] = root;
            changes++;
        }
    }

    cout << changes << endl;
    for (int i = 0; i < n; i++) {
        cout << parent[i] << " ";
    }
    
    return 0;
}