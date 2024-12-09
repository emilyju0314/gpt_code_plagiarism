#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    int maxDistance = 0;
    int firstDifferentColorIndex = 0;
    int lastDifferentColorIndex = n-1;

    // Find the index of the first house with a different color
    while(colors[firstDifferentColorIndex] == colors[0]) {
        firstDifferentColorIndex++;
    }

    // Find the index of the last house with a different color
    while(colors[lastDifferentColorIndex] == colors[n-1]) {
        lastDifferentColorIndex--;
    }

    // Calculate the maximum possible distance
    maxDistance = max(firstDifferentColorIndex, n-1 - lastDifferentColorIndex);

    cout << maxDistance << endl;

    return 0;
}