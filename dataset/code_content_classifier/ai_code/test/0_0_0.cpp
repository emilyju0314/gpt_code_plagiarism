#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i+1;
    }

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return compare(books[a-1], books[b-1]);
    });

    for (int i = 0; i < n; i++) {
        cout << idx[i] << " ";
    }

    return 0;
}