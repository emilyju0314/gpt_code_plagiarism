#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

unordered_map<string, vector<string>> baseChords = {
    {"C", {"C", "E", "G"}},
    {"Cm", {"C", "D#", "G"}},
    {"C7", {"C", "E", "G", "Bb"}},
    {"Cmaj7", {"C", "E", "G", "B"}},
    {"Caug", {"C", "E", "G#"}}
};

string replaceSharp(string tone) {
    if (tone.find("#") != string::npos) {
        return tone.substr(0, 1) + "s";
    }
    return tone;
}

bool isTension(string tone) {
    return tone.find("(") != string::npos && tone.find(")") != string::npos;
}

string trimTone(string tone) {
    return tone.substr(0, tone.find("("));
}

int main() {
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; t++) {
        int numTones;
        cin >> numTones;

        set<string> tones;
        for (int i = 0; i < numTones; i++) {
            string tone;
            cin >> tone;
            tones.insert(replaceSharp(tone));
        }

        bool foundChord = false;
        for (auto& baseChord : baseChords) {
            set<string> chordTones;
            for (auto& tone : baseChord.second) {
                chordTones.insert(tone);
            }

            bool toneMatch = true;

            for (auto& t : tones) {
                if (chordTones.find(trimTone(t)) == chordTones.end()) {
                    toneMatch = false;
                    break;
                }
            }

            if (toneMatch) {
                foundChord = true;
                cout << baseChord.first;
                for (auto& t : tones) {
                    if (isTension(t)) {
                        cout << "(" << trimTone(t) << ")";
                    } else {
                        cout << "(" << t << ")";
                    }
                }
                cout << " ";
            }
        }

        if (!foundChord) {
            cout << "UNKNOWN";
        }

        cout << endl;
    }

    return 0;
}