#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n, m, a;
        cin >> n >> m >> a;

        if (n == 0 && m == 0 && a == 0) {
            break;
        }

        vector<int> vertical_lines(n+1);
        
        for (int i = 1; i <= n; i++) {
            vertical_lines[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int h, p, q;
            cin >> h >> p >> q;
            swap(vertical_lines[p], vertical_lines[q]);
        }

        cout << vertical_lines[a] << endl;
    }

    return 0;
}