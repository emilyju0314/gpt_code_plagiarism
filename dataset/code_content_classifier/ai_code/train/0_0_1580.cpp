#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        
        vector<int> pattyCakes(n);
        map<int, vector<int>> indices;

        for (int i = 0; i < n; i++) {
            cin >> pattyCakes[i];
            indices[pattyCakes[i]].push_back(i);
        }

        int maxDist = 0;

        for (auto& it : indices) {
            vector<int>& indicesVec = it.second;
            int size = indicesVec.size();

            for (int i = 1; i < size; i++) {
                int dist = indicesVec[i] - indicesVec[i - 1] - 1;
                maxDist = max(maxDist, dist);
            }
        }

        cout << maxDist << endl;
    }

    return 0;
}