#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    unordered_set<int> uniqueColors(colors.begin(), colors.end());

    int min_turns = n;
    for (auto color : uniqueColors) {
        int turns = 0;
        int prev_color = -1;
        for (int i = 0; i < n; i++) {
            if (colors[i] == color && prev_color != color) {
                turns++;
            }
            prev_color = colors[i];
        }
        min_turns = min(turns, min_turns);
    }

    cout << min_turns << endl;

    return 0;
}