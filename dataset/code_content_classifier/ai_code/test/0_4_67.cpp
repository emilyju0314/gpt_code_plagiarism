#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    double P;
    cin >> N >> P;

    int maps_to_study = ceil(N * (1 - P));

    cout << maps_to_study << endl;

    return 0;
} 

// Input: 7 1.0000
// Output: 6