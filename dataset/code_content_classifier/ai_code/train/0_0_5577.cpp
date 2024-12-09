#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<unordered_map<int, long long>> sets(m);

    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++) {
            int element;
            cin >> element;
            sets[i][element-1] = 0;
        }
    }

    for (int i = 0; i < q; i++) {
        char query_type;
        int k;
        cin >> query_type >> k;
        k--;

        if (query_type == '?') {
            long long sum = 0;
            for (auto& entry : sets[k]) {
                sum += a[entry.first];
            }
            cout << sum << endl;
        } else if (query_type == '+') {
            int x;
            cin >> x;
            for (auto& entry : sets[k]) {
                a[entry.first] += x;
            }
        }
    }

    return 0;
}