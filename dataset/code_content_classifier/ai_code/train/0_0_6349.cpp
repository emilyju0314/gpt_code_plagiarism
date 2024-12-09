#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int time = 0;
    for(int i = 0; i < n-1; i++) {
        // Walking up to reach the next tree
        time += heights[i] - 1;
        // Jumping to the next tree
        time += 1;
    }

    // Eating the nut on the last tree
    time += heights[n-1];

    // Adding the time taken to eat all nuts
    cout << time << endl;

    return 0;
}