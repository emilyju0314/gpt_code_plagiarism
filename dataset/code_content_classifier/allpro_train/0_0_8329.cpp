#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> presents(n + 1), target(m + 1);
        map<int, int> pos;

        for(int i = 1; i <= n; i++) {
            cin >> presents[i];
            pos[presents[i]] = i;
        }

        for(int i = 1; i <= m; i++) {
            cin >> target[i];
        }

        int max_pos = 0, res = 0;

        for(int i = 1; i <= m; i++) {
            if(pos[target[i]] < max_pos) {
                res += 1;
            } else {
                res += (2 * (pos[target[i]] - i)) + 1;
                max_pos = max(max_pos, pos[target[i]]);
            }
        }

        cout << res << endl;
    }

    return 0;
}