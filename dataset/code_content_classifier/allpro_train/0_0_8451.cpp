#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<string> allPossible = {"0123", "4567", "8901", "2345", "6789", "1234", "5678", "9012"};
    
    do {
        bool found = false;
        for (const string& s : allPossible) {
            cout << s << endl;
            cout.flush();
            int bulls, cows;
            cin >> bulls >> cows;
            if (bulls == 4 && cows == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    } while (next_permutation(allPossible.begin(), allPossible.end()));
    
    return 0;
}