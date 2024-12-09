#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::vector<int> notes(n);
        std::unordered_set<int> uniqueNotes;

        for(int j = 0; j < n; j++) {
            std::cin >> notes[j];
            uniqueNotes.insert(notes[j]);
        }

        int maxDiversity = uniqueNotes.size();
        for(int j = 0; j < n; j++) {
            if(uniqueNotes.count(notes[j]) > 1) {
                if(uniqueNotes.count(notes[j] + 1) == 0) {
                    uniqueNotes.insert(notes[j] + 1);
                    maxDiversity++;
                }
            }
        }

        std::cout << maxDiversity << std::endl;
    }

    return 0;
}