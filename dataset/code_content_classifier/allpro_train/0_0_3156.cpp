#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<bool> row(n + 1, false);
    vector<bool> col(m + 1, false);

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        row[x] = true;
        col[y] = true;
    }

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool protected = false;
        for(int x = x1; x <= x2; x++) {
            if(!row[x]) {
                for(int y = y1; y <= y2; y++) {
                    if(!col[y]) {
                        protected = true;
                        break;
                    }
                }
            }
            if(protected) break;
        }

        if(protected) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}