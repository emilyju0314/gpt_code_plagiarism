#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string notes;
    cin >> notes;

    vector<string> triad(3);
    for(int i = 0; i < 3; i++) {
        triad[i] = notes.substr(i*2, 1);
    }

    int semitones12[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};

    int diff1 = (semitones12[triad[1][0]-'A'] - semitones12[triad[0][0]-'A'] + 12) % 12;
    int diff2 = (semitones12[triad[2][0]-'A'] - semitones12[triad[1][0]-'A'] + 12) % 12;

    if((diff1 == 4 && diff2 == 3) || (diff1 == 8 && diff2 == 5)) {
        cout << "major" << endl;
    } else if((diff1 == 3 && diff2 == 4) || (diff1 == 9 && diff2 == 8)) {
        cout << "minor" << endl;
    } else {
        cout << "strange" << endl;
    }

    return 0;
}