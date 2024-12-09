#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int countVK = 0;
    int countK = 0;
    int countNotK = 0;
    int countV = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V' && i+1 < n && s[i+1] == 'K') {
            countVK++;
            i++;
        } else if (s[i] == 'K') {
            countK++;
        } else if (s[i] == 'V') {
            countV++;
        } else {
            countNotK++;
        }
    }

    // Count the number of moves needed to swap 'K's to the right
    // and 'V's to the left of the 'VK' substring
    int moves = 0;
    moves += min(countK, countVK);
    countK -= moves;
    countVK -= moves;
    moves += min(countV, countVK);
    countV -= moves;
    countVK -= moves;
    moves += countVK + min(countK, countV);

    cout << moves << endl;

    return 0;
}