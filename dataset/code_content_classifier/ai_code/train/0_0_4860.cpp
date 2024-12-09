#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<vector<int>> positions(26); // Vector to store the positions of each character

    // Populate the vector of vectors with the positions of each character
    for (int i = 0; i < s.size(); i++) {
        positions[s[i] - 'a'].push_back(i);
    }

    long long totalDistance = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (i == j) {
                totalDistance += 0; // Same character, distance is 0
            } else {
                char c = s[j]; // Character to move to

                int currentPos = positions[s[i] - 'a'][0]; // Current position of the cursor
                int minDistance = abs(currentPos - i); // Initialize minimum distance

                for (int newPos : positions[c - 'a']) {
                    minDistance = min(minDistance, abs(newPos - currentPos));
                }

                totalDistance += minDistance; // Add the minimum distance to the total
            }
        }
    }

    cout << totalDistance << endl;

    return 0;
}