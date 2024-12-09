#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinimumVisibleVolume(vector<vector<int>>& dolls) {
    sort(dolls.begin(), dolls.end(), greater<vector<int>>());

    vector<int> maxVolumes(dolls.size(), 0);

    for (int i = 0; i < dolls.size(); i++) {
        int maxVolume = dolls[i][0] * dolls[i][1] * dolls[i][2];

        for (int j = i + 1; j < dolls.size(); j++) {
            if (dolls[i][0] >= dolls[j][0] && dolls[i][1] >= dolls[j][1] && dolls[i][2] >= dolls[j][2]) {
                maxVolume -= dolls[j][0] * dolls[j][1] * dolls[j][2];
            }
        }

        maxVolumes[i] = maxVolume;
    }

    return accumulate(maxVolumes.begin(), maxVolumes.end(), 0);
}

int main() {
    int N;
    
    while (cin >> N && N > 0) {
        vector<vector<int>> dolls(N, vector<int>(3));

        for (int i = 0; i < N; i++) {
            cin >> dolls[i][0] >> dolls[i][1] >> dolls[i][2];
        }

        cout << getMinimumVisibleVolume(dolls) << endl;
    }

    return 0;
}