#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cyclic_shift(vector<int>& a, int l, int r, int d) {
    reverse(a.begin() + l - 1, a.begin() + r);
    reverse(a.begin() + l - 1, a.begin() + l - 1 + d);
    reverse(a.begin() + l - 1 + d, a.begin() + r);
}

void sort_array(vector<int>& a) {
    int n = a.size();
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    vector<pair<int, int>> unsorted_pairs;
    for (int i = 0; i < n; i++) {
        if (a[i] != sorted_a[i]) {
            int j = i;
            while (j < n && a[j] != sorted_a[j]) 
                j++;
            unsorted_pairs.push_back({i, j});
            i = j - 1;
        }
    }

    cout << unsorted_pairs.size() << endl;
    for (int i = 0; i < unsorted_pairs.size(); i++) {
        int l = unsorted_pairs[i].first + 1;
        int r = unsorted_pairs[i].second;
        int d = r - l + 1;
        cout << l << " " << r << " " << d << endl;
        cyclic_shift(a, l, r, d);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort_array(a);
        for (int num : a)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}