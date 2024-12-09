#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        vector<pair<int, int>> edges;
        for (int i = 1; i < N; i++) {
            edges.push_back({i, i+1});
            edges.push_back({N+i, N+i+1});
            edges.push_back({i, N+i});
        }

        edges.push_back({N, 2*N});
        
        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}