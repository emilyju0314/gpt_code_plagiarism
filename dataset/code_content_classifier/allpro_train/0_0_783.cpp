#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> boxes(n);
    vector<unordered_map<int, int>> counts(n);

    int total_presents = 0;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        total_presents += s;
        boxes[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> boxes[i][j];
            counts[i][boxes[i][j]]++;
        }
    }

    int target = total_presents / n;
    int excess_boxes = total_presents % n;
    
    vector<pair<int, pair<int, int>>> moves;

    int i = 0, j = n - 1;
    while (i < j) {
        while (boxes[i].size() > target) {
            int kind = boxes[i].back();
            if (counts[j][kind] < target) {
                moves.push_back({i+1, j+1, kind});
                counts[j][kind]++;
                counts[i][kind]--;
                boxes[j].push_back(kind);
                boxes[i].pop_back();
            } else {
                j--;
            }
        }
        i++;
    }

    cout << moves.size() << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << " " << move.second << endl;
    }

    return 0;
}