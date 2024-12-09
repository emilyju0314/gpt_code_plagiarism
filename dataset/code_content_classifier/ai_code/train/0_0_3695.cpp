#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n; i++) {
        unordered_set<string> substrings;
        string number = numbers[i];
        
        for (int j = 1; j < number.size(); j++) {
            for (int k = 0; k + j <= number.size(); k++) {
                substrings.insert(number.substr(k, j));
            }
        }

        for (const string& sub : substrings) {
            bool unique = true;
            for (int m = 0; m < n; m++) {
                if (m != i && numbers[m].find(sub) != string::npos) {
                    unique = false;
                    break;
                }
            }
            if (unique) {
                cout << sub << endl;
                break;
            }
        }
    }

    return 0;
}