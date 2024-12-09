#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pipe {
    int from, to, diameter;
};

int main() {
    int n, p;
    cin >> n >> p;

    vector<Pipe> pipes(p);
    for (int i = 0; i < p; i++) {
        cin >> pipes[i].from >> pipes[i].to >> pipes[i].diameter;
    }

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<int> tank, tap;

    for (int i = 0; i < p; i++) {
        outDegree[pipes[i].from]++;
        inDegree[pipes[i].to]++;
    }

    for (int i = 1; i <= n; i++) {
        if (outDegree[i] > 0 && inDegree[i] == 0) {
            tap.push_back(i);
        }
        if (inDegree[i] > 0 && outDegree[i] == 0) {
            tank.push_back(i);
        }
    }

    cout << min(tank.size(), tap.size()) << endl;
    int t = min(tank.size(), tap.size());
    for (int i = 0; i < t; i++) {
        cout << tank[i] << " " << tap[i] << " ";
        for (int j = 0; j < p; j++) {
            if (pipes[j].from == tank[i] && pipes[j].to == tap[i]) {
                cout << pipes[j].diameter << endl;
                break;
            }
        }
    }

    return 0;
}