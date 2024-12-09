#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string sequence;

    while (true) {
        cin >> sequence;
        if (sequence == "0") break;

        int length = sequence.size();
        int count = 0;
        bool possible = false;

        while (count <= 10) {
            if (count > 1 && sequence.length() == 1) {
                possible = true;
                break;
            }

            if (all_of(sequence.begin(), sequence.end(), [&](char c) { return c == sequence[0]; })) {
                possible = true;
                break;
            }

            string new_sequence = "";
            for (int i = 0; i < length - 1; i++) {
                if (sequence[i] != sequence[i + 1]) {
                    if ((sequence[i] == 'r' && sequence[i + 1] == 'g') || 
                        (sequence[i] == 'g' && sequence[i + 1] == 'r')) {
                        new_sequence += 'b';
                    } else if ((sequence[i] == 'r' && sequence[i + 1] == 'b') || 
                               (sequence[i] == 'b' && sequence[i + 1] == 'r')) {
                        new_sequence += 'g';
                    } else if ((sequence[i] == 'g' && sequence[i + 1] == 'b') || 
                               (sequence[i] == 'b' && sequence[i + 1] == 'g')) {
                        new_sequence += 'r';
                    }
                    i++;
                } else {
                    new_sequence += sequence[i];
                }
            }
            if (length % 2 == 1) {
                new_sequence += sequence.back();
            }

            sequence = new_sequence;
            count++;
        }

        if (possible) {
            cout << count << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}