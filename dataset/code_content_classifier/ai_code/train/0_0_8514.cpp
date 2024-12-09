#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bridges(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> bridges[i];
    }

    long long points = bridges[0]; // Points for the first bridge
    for (int i = 1; i < n-1; i++) {
        points += min(bridges[i], bridges[i-1]); // Add min of current bridge and previous bridge
    }

    points += bridges[n-2]; // Add points for the last bridge

    cout << points << endl;

    return 0;
}