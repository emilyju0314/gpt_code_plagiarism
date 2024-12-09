#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minimumDominatingSet(int n, vector<pair<int, int>> edges) {
    vector<int> vertices(n, 0);
    for(auto edge : edges) {
        vertices[edge.first]++;
        vertices[edge.second]++;
    }

    int count = 0;
    set<int> dominatingSet;

    while(vertices[0] > 0) {
        dominatingSet.insert(0);
        count++;

        for(auto edge : edges) {
            if(edge.first == 0) {
                vertices[edge.second]--;
            } else if(edge.second == 0) {
                vertices[edge.first]--;
            }
        }

        vertices[0] = 0;
    }

    for(int i = 1; i < n; i++) {
        if(vertices[i] > 0) {
            dominatingSet.insert(i);
            count++;

            for(auto edge : edges) {
                if(edge.first == i) {
                    vertices[edge.second]--;
                } else if(edge.second == i) {
                    vertices[edge.first]--;
                }
            }

            vertices[i] = 0;
        }
    }

    return count;
}

int main() {
    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }
        
        vector<pair<int, int>> edges;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back(make_pair(u, v));
        }

        int result = minimumDominatingSet(n, edges);
        cout << result << endl;
    }

    return 0;
}