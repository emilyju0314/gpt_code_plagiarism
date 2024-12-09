#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> distances(n);
    for(int i = 0; i < n; i++) {
        cin >> distances[i];
    }

    sort(distances.begin(), distances.end());

    int maxLocations = 1;
    int k = 1;

    for(int i = 1; i < n; i++) {
        // Compute the possible k by taking the difference between the distances
        int possibleK = distances[i] - distances[i-1];

        // Count the number of locations that can be created with this k
        int numLocations = i;

        // If each location has the same number of days, update maxLocations and k
        if(n % numLocations == 0 && possibleK < distances[n/numLocations]) {
            maxLocations = numLocations;
            k = possibleK;
        }
    }

    cout << k << endl;

    return 0;
}