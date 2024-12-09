#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* schedule = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> schedule[i];
    }

    int pairs_stayed = 0;
    int current_pairs = 0;
    for (int i = 0; i < n; i++) {
        if (schedule[i] == 1) {
            current_pairs++;
        } else {
            if (current_pairs >= 2) {
                pairs_stayed += current_pairs;
                current_pairs = 0;
            } else {
                current_pairs = 0;
            }
        }
    }

    if (current_pairs >= 2) {
        pairs_stayed += current_pairs;
    }

    cout << pairs_stayed << endl;

    return 0;
}