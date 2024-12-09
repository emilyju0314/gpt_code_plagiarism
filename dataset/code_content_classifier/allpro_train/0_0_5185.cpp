#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M && N != 0 && M != 0) {
        map<int, int> weights;
        vector<pair<int, int>> edges;
        
        for (int i = 0; i < M; i++) {
            char type;
            cin >> type;
            if (type == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                weights[b] = weights[a] + w;
                edges.push_back({a, b});
            } else if (type == '?') {
                int a, b;
                cin >> a >> b;
                int wa = (weights.find(a) != weights.end()) ? weights[a] : -1;
                int wb = (weights.find(b) != weights.end()) ? weights[b] : -1;
                if (wa != -1 && wb != -1) {
                    cout << wb - wa << endl;
                } else {
                    bool found = false;
                    for (const auto& edge : edges) {
                        if (edge.first == a && edge.second == b) {
                            cout << weights[b] - weights[a] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "UNKNOWN" << endl;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}