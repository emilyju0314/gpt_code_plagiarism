#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Lemming {
    int weight;
    int speed;
    int index;
};

bool compareWeights(const Lemming &lem1, const Lemming &lem2) {
    return lem1.weight < lem2.weight;
}

int main() {
    int n, k, h;
    cin >> n >> k >> h;

    vector<Lemming> lemmings(n);
    for (int i = 0; i < n; i++) {
        cin >> lemmings[i].weight;
        lemmings[i].index = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> lemmings[i].speed;
    }

    sort(lemmings.begin(), lemmings.end(), compareWeights);

    vector<int> selectedLemmings(k);
    for (int i = 0; i < k; i++) {
        selectedLemmings[i] = lemmings[n - k + i].index;
    }

    for (int i = 0; i < k; i++) {
        cout << selectedLemmings[i] << " ";
    }
    cout << endl;

    return 0;
}