#include <iostream>
#include <unordered_map>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> encoding;
    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;
        encoding[code] = i;
    }

    int minAmbiguous = 0;

    for (auto it1 = encoding.begin(); it1 != encoding.end(); ++it1) {
        for (auto it2 = encoding.begin(); it2 != encoding.end(); ++it2) {
            if (it1 != it2) {
                string code1 = it1->first;
                string code2 = it2->first;
                int len1 = code1.size();
                int len2 = code2.size();

                string concat1 = code1 + code2.substr(0, len1);
                string concat2 = code2 + code1.substr(0, len2);

                if (encoding.find(concat1) != encoding.end() && encoding.find(concat2) != encoding.end()) {
                    int ambiguity = max(concat1.size(), concat2.size());
                    if (minAmbiguous == 0 || ambiguity < minAmbiguous) {
                        minAmbiguous = ambiguity;
                    }
                }
            }
        }
    }

    cout << minAmbiguous << endl;

    return 0;
}