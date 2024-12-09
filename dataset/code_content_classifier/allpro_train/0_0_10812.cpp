#include <iostream>
using namespace std;

int main() {
    int scores[10];
    int total = 0;

    // Input scores
    for (int i = 0; i < 10; i++) {
        cin >> scores[i];
    }

    // Calculate total score
    for (int i = 0; i < 10; i++) {
        total += scores[i];
    }

    // Output total score
    cout << total << endl;

    return 0;
}