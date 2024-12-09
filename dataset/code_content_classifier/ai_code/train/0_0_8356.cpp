#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n);
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) {
        int degree, xor_sum;
        cin >> degree >> xor_sum;
        vertices[i] = {degree, xor_sum};
    }

    int total_edges = 0;
    for (int i = 0; i < n; i++) {
        total_edges += vertices[i].first;
    }
    total_edges /= 2;

    cout << total_edges << endl;

    for (int i = 0; i < n; i++) {
        while (vertices[i].first > 0) {
            int j = i + 1;
            while (vertices[j].first == 0) {
                j++;
            }
            vertices[i].first--;
            vertices[j].first--;
            edges.push_back({i, j});
        }
    }

    for (int i = 0; i < total_edges; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}