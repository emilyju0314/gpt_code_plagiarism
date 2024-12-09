#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;

    vector<int> floodedAreas;
    int totalArea = 0;

    int waterLevel = 0;
    for (char c : input) {
        if (c == '\\') {
            waterLevel++;
        } else if (c == '/') {
            waterLevel--;
            if (waterLevel >= 0) {
                totalArea += waterLevel;
            }
        }
        floodedAreas.push_back(totalArea);
    }

    cout << totalArea << endl;

    int prevFloodedArea = 0;
    vector<int> floodSizes;
    for (int i = 1; i < floodedAreas.size(); i++) {
        if (floodedAreas[i] > floodedAreas[i - 1]) {
            floodSizes.push_back(floodedAreas[i] - prevFloodedArea);
            prevFloodedArea = floodedAreas[i];
        }
    }

    cout << floodSizes.size() << " ";
    for (int floodSize : floodSizes) {
        cout << floodSize << " ";
    }
    cout << endl;

    return 0;
}