#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> substrings;

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            cout << "? " << l << " " << r << endl;
            string input;
            cin >> input;
            if (input == "-") {
                exit(0);
            }
            for (char c : input) {
                substrings.push_back(string(1, c));
            }
        }
    }

    sort(substrings.begin(), substrings.end());
    string guessed_string;

    do {
        random_shuffle(substrings.begin(), substrings.end());
        guessed_string = "";
        for (string s : substrings) {
            guessed_string += s;
        }
        
        cout << "! " << guessed_string << endl;
        string result;
        cin >> result;
        if (result == "-") {
            exit(0);
        }
    } while (result != "Correct");

    return 0;
}