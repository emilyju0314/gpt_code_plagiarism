#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    map<int, int> minColor; // To store the minimum color assigned to each value
    
    int colors = 0; // To keep track of the number of colors used
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        auto it = minColor.lower_bound(num); // Find the lower bound of the current number
        
        if (it == minColor.begin()) {
            // If no lower bound found, assign a new color
            minColor[num] = ++colors;
        } else {
            // Use the color of the previous value
            minColor[num] = it->second;
            minColor.erase(it); // Erase the previous entry
        }
    }

    cout << colors << endl; // Output the minimum number of colors used

    return 0;
}