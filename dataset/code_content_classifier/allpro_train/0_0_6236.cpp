#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pipe {
    int start;
    int end;
    int diameter;
};

int main() {
    int n, p;
    cin >> n >> p;

    vector<Pipe> pipes(p);
    vector<int> out_degree(n, 0);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < p; i++) {
        cin >> pipes[i].start >> pipes[i].end >> pipes[i].diameter;
        out_degree[pipes[i].start - 1]++;
        in_degree[pipes[i].end - 1]++;
    }

    vector<pair<int, int>> tanks_taps;
    for (int i = 0; i < n; i++) {
        if (out_degree[i] > 0 && in_degree[i] == 0) {
            int tank = i + 1;
            int tap = pipes[i].end;
            int diameter = pipes[i].diameter;
            tanks_taps.push_back({tank, tap, diameter});
        }
    }

    sort(tanks_taps.begin(), tanks_taps.end());

    cout << tanks_taps.size() << endl;
    for (auto pair : tanks_taps) {
        cout << pair.first << " " << pair.second << " " << pair.second << endl;
    }

    return 0;
}