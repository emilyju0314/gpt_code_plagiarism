#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n);
    int total_edges = 0;

    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
        total_edges += vertices[i].first;
    }

    total_edges /= 2;

    cout << total_edges << endl;

    for (int i = 0; i < n; i++) {
        while (vertices[i].first > 0) {
            for (int j = i + 1; j < n; j++) {
                if (vertices[j].first > 0 && (vertices[i].second ^ vertices[j].second) == 0) {
                    cout << i << " " << j << endl;
                    vertices[i].first--;
                    vertices[j].first--;
                    break;
                }
            }
        }
    }

    return 0;
}