#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> notes(n);
    for(int i = 0; i < n; i++) {
        std::cin >> notes[i];
    }

    std::vector<int> fingers(n);
    fingers[0] = 1;

    for(int i = 1; i < n; i++) {
        if(notes[i] < notes[i-1]) {
            fingers[i] = fingers[i-1] - 1;
            if(fingers[i] < 1) fingers[i] = 5;
        } else if(notes[i] > notes[i-1]) {
            fingers[i] = fingers[i-1] + 1;
            if(fingers[i] > 5) fingers[i] = 1;
        } else {
            fingers[i] = fingers[i-1];
            if(fingers[i] == 1) fingers[i]++;
            else fingers[i]--;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << fingers[i] << " ";
    }

    return 0;
}