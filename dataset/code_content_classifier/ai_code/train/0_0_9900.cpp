#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> colors(n);
    unordered_map<int, int> colorIndex;

    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    for(int i = n-1; i >= 0; i--) {
        if(colorIndex.find(colors[i]) == colorIndex.end()) {
            colorIndex[colors[i]] = i;
        }
    }

    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    for(int i = 0; i < q; i++) {
        int color = queries[i];
        int index = colorIndex[color];
        cout << index + 1 << " ";

        for(auto& pair : colorIndex) {
            if(pair.second < index) {
                pair.second++;
            }
        }

        colorIndex[color] = 0;
    }

    return 0;
}