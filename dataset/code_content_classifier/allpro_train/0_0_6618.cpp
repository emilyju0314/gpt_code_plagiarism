#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cups(n + 1);
    for(int i = 1; i <= n; i++) {
        cups[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if(cups[y] == x) {
            continue;
        }

        if(cups[1] == x) {
            int temp = cups[y];
            cups[y] = cups[1];
            cups[1] = temp;
        } else {
            cups[cups[y]] = cups[x];
            cups[x] = cups[y];
            cups[y] = x;
        }
    }

    vector<int> result(n + 1);
    for(int i = 1; i <= n; i++) {
        result[cups[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}