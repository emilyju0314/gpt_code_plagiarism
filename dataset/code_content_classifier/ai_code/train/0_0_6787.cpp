#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct volcano {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<volcano> volcanoes(m);
    for(int i = 0; i < m; i++) {
        cin >> volcanoes[i].x >> volcanoes[i].y;
    }

    sort(volcanoes.begin(), volcanoes.end(), [](const volcano &a, const volcano &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    int min_time = -1;

    for(int i = 0; i < m; i++) {
        if (volcanoes[i].x <= volcanoes[i].y && volcanoes[i + 1].x <= volcanoes[i + 1].y) {
            min_time = max(min_time, 2 * (volcanoes[i+1].x - 1));
        }
    }
  
    cout << min_time << endl;

    return 0;
}