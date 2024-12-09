#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string left_pan, right_pan, unused_weights;
    string input, weights;

    cin >> input;
    cin >> weights;

    int delimiter_pos = input.find('|');
    left_pan = input.substr(0, delimiter_pos);
    right_pan = input.substr(delimiter_pos + 1);

    for (char weight : weights) {
        // Check if the weight is already on the left or right pan
        if (left_pan.find(weight) == string::npos && right_pan.find(weight) == string::npos) {
            unused_weights += weight;
        }
    }

    // Initialize variables to hold potential left and right pans
    string new_left_pan = left_pan + unused_weights;
    string new_right_pan = right_pan;

    // Sort the unused weights to find the lexicographically smallest solution
    sort(unused_weights.begin(), unused_weights.end());

    // Check if equilibrium can be achieved by moving weights from the unused weights to either the left or right pans
    while (unused_weights.size() > 0) {
        char weight = unused_weights.back();
        unused_weights.pop_back();

        if (new_left_pan.size() <= new_right_pan.size()) {
            new_left_pan += weight;
        } else {
            new_right_pan += weight;
        }
    }

    // Check if the scales are in equilibrium
    if (new_left_pan.size() == new_right_pan.size()) {
        cout << new_left_pan << "|" << new_right_pan << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}