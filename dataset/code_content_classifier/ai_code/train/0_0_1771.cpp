#include <bits/stdc++.h>
using namespace std;

bool check_cube(vector<vector<int>>& vertices) {
    sort(vertices.begin(), vertices.end());
    vector<vector<int>> edges;

    for(int i = 0; i < 8; ++i) {
        for(int j = i + 1; j < 8; ++j) {
            vector<int> edge;
            for(int k = 0; k < 3; ++k) {
                edge.push_back(vertices[j][k] - vertices[i][k]);
            }
            edges.push_back(edge);
        }
    }

    sort(edges.begin(), edges.end());

    return edges[0] == edges[3] && edges[4] == edges[7] && edges[0] != edges[4];
}

int main() {
    vector<vector<int>> vertices(8, vector<int>(3));
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> vertices[i][j];
        }
    }

    if(check_cube(vertices)) {
        cout << "YES" << endl;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 3; ++j) {
                cout << vertices[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}