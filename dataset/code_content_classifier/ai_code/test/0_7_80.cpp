#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long merge(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size() + b.size());
    long long inversions = 0;
    int i = 0, j = 0, k = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
            inversions += (a.size() - i);
        }
    }

    while(i < a.size()) c[k++] = a[i++];
    while(j < b.size()) c[k++] = b[j++];

    a = c;

    return inversions;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());

        long long inversions = merge(a, b);

        cout << inversions << endl;
    }

    return 0;
}