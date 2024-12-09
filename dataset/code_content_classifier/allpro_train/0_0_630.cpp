#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    map<pair<int, int>, int> edge_count;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        edge_count[{a, b}]++;
        edge_count[{b, a}]++;
    }

    long long triangles = 0;
    for(auto edge : edges) {
        int a = edge.first;
        int b = edge.second;
        
        long long cnt = edge_count[{a, b}];
        triangles += cnt * (cnt - 1) / 2;
    }

    long long total_triangles = (long long)n * (n - 1) * (n - 2) / 6;
    cout << total_triangles - triangles << endl;

    return 0;
}