#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pathway {
    int u, v, a, b;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Pathway> pathways(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> pathways[i].u >> pathways[i].v >> pathways[i].a >> pathways[i].b;
    }

    vector<int> max_lengths(n, 0);

    for(int t = 0; t < m; t++) {
        int max_length = 0;
        for(int i = 0; i < n - 1; i++) {
            int length = pathways[i].a * t + pathways[i].b;
            max_length = max(max_length, length);
        }

        for(int i = 0; i < n; i++) {
            max_lengths[i] = max(max_lengths[i], max_length);
        }
    }

    for(int i = 0; i < m; i++) {
        cout << max_lengths[i] << " ";
    }
    cout << endl;

    return 0;
}