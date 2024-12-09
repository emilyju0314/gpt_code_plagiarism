#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    vector<int> xaniar_sequence;
    vector<int> abol_sequence;
    unordered_map<int, int> xaniar_index;
    unordered_map<int, int> abol_index;

    // Simulate Xaniar's height sequence
    int xaniar_height = h1;
    int xaniar_steps = 0;
    while (xaniar_index.find(xaniar_height) == xaniar_index.end()) {
        xaniar_sequence.push_back(xaniar_height);
        xaniar_index[xaniar_height] = xaniar_steps++;
        xaniar_height = (xaniar_height * x1 + y1) % m;
    }

    // Simulate Abol's height sequence
    int abol_height = h2;
    int abol_steps = 0;
    while (abol_index.find(abol_height) == abol_index.end()) {
        abol_sequence.push_back(abol_height);
        abol_index[abol_height] = abol_steps++;
        abol_height = (abol_height * x2 + y2) % m;
    }

    int min_steps = max(xaniar_index[h1], abol_index[h2]);
    
    for (int i = 0; i < min(xaniar_steps, abol_steps); i++) {
        if (xaniar_sequence[i] == abol_sequence[i]) {
            cout << i + min_steps << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}