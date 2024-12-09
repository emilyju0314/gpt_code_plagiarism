#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> a_lastpos;
    unordered_map<int, int> b_lastpos;

    for (int i = 0; i < m; i++) {
        char query_type;
        cin >> query_type;

        if (query_type == '1') {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            int count = 0;

            for (int j = la-1; j < ra; j++) {
                a_lastpos[a[j]] = j;
            }

            for (int j = lb-1; j < rb; j++) {
                b_lastpos[b[j]] = j;
            }

            for (auto it = a_lastpos.begin(); it != a_lastpos.end(); it++) {
                if (b_lastpos.find(it->first) != b_lastpos.end()) {
                    count++;
                }
            }

            cout << count << endl;
        } else if (query_type == '2') {
            int x, y;
            cin >> x >> y;
            swap(b[x-1], b[y-1]);
        }
    }

    return 0;
}