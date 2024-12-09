#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> respect_levels(n);
    for(int i = 0; i < n; i++) {
        cin >> respect_levels[i];
    }

    vector<int> seconds_needed(n);

    for(int i = 0; i < n; i++) {
        int seconds = 1;

        int left = (i - 1 + n) % n; // Calculate the left neighbour index
        int right = (i + 1) % n; // Calculate the right neighbour index

        while(respect_levels[left] >= respect_levels[i]) {
            seconds++;
            left = (left - 1 + n) % n;
        }

        while(respect_levels[right] >= respect_levels[i]) {
            seconds++;
            right = (right + 1) % n;
        }

        seconds_needed[i] = seconds;
    }

    for(int i = 0; i < n; i++) {
        cout << seconds_needed[i] << " ";
    }

    return 0;
}