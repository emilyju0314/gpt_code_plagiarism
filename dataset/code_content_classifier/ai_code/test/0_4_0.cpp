#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    int n = a.length();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        } else {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i + 1;
    }

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return compare(books[a - 1], books[b - 1]);
    });

    for (int i = 0; i < n; ++i) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}