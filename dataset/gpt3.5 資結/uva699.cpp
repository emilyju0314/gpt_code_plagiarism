#include <iostream>
#include <vector>
using namespace std;

void calculateWater(vector<int>& waterLevels, vector<int>& ponds, int position) {
    // Base case: if water level at position is 0, return
    if (waterLevels[position] == 0) {
        return;
    }

    // Add water to the current pond
    ponds[position] += waterLevels[position];

    // Update the water levels of left and right children
    calculateWater(waterLevels, ponds, position - 1);
    calculateWater(waterLevels, ponds, position + 1);

    // Subtract water from current position
    waterLevels[position] = 0;
}

int main() {
    int caseNumber = 1;
    while (true) {
        int position;
        vector<int> waterLevels;
        while (cin >> position) {
            if (position == -1) {
                break;
            }
            waterLevels.push_back(position);
        }

        // Base case: stop if no more input
        if (waterLevels.empty()) {
            break;
        }

        vector<int> ponds(waterLevels.size(), 0);
        int center = waterLevels.size() / 2;
        calculateWater(waterLevels, ponds, center);

        cout << "Case " << caseNumber << ":" << endl;
        for (int i = 0; i < ponds.size(); i++) {
            cout << ponds[i];
            if (i < ponds.size() - 1) {
                cout << " ";
            }
        }
        cout << endl << endl;

        caseNumber++;
    }

    return 0;
}