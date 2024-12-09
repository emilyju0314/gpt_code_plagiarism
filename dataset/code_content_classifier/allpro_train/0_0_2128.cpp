#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> happiness(n);
    for(int i = 0; i < n; i++) {
        cin >> happiness[i];
    }

    vector<string> pickupLines(n);
    for(int i = 0; i < n; i++) {
        cin >> pickupLines[i];
    }

    string text;
    for(int i = 0; i < l; i++) {
        text += 'a'; // add arbitrary character to initialize text
    }

    int maxHappiness = 0;
    do {
        int happinessLevel = 0;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < n; j++) {
                if(i + pickupLines[j].size() <= l) {
                    if(text.substr(i, pickupLines[j].size()) == pickupLines[j]) {
                        happinessLevel += happiness[j];
                    }
                }
            }
        }
        maxHappiness = max(maxHappiness, happinessLevel);
    } while(next_permutation(text.begin(), text.end()));

    cout << maxHappiness << endl;

    return 0;
}