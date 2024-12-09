#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> connections[n+1];
    vector<int> mushrooms(n+1);

    for (int i = 0; i < m; i++) {
        int x, y, g, l;
        cin >> x >> y >> g >> l;
        connections[x].push_back({y, g});
        connections[y].push_back({x, g});
        mushrooms[x] = l / g;
    }

    for (int i = 1; i <= n; i++) {
        if (mushrooms[i] == 0) {
            for (pair<int, int> p : connections[i]) {
                int j = p.first;
                int g = p.second;
                if (mushrooms[j] != 0) {
                    mushrooms[i] = l / g;
                    break;
                }
            }
        }
    }

    int first_g = connections[1][0].second;
    int first_mush = l / first_g;

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (mushrooms[i] == 0 || gcd(first_mush, mushrooms[i]) != connections[1][i].first) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << mushrooms[i] << " ";
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}