#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;

    int maxDistance = 0;

    for (int useMagic1 = 0; useMagic1 <= min(K, (int)S.size()); useMagic1++) {
        for (int useMagic2 = 0; useMagic2 <= min(K - useMagic1, (int)S.size()); useMagic2++) {
            int x = 0, y = 0;
            string modifiedS = S;
            
            for (int i = 0; i < S.size(); i++) {
                if (useMagic1 > 0) {
                    modifiedS[i] = (modifiedS[i] == 'U') ? 'D' : (modifiedS[i] == 'D' ? 'U' : modifiedS[i]);
                    useMagic1--;
                }
                if (useMagic2 > 0) {
                    modifiedS[i] = (modifiedS[i] == 'L') ? 'R' : (modifiedS[i] == 'R' ? 'L' : modifiedS[i]);
                    useMagic2--;
                }

                if (modifiedS[i] == 'U') y++;
                else if (modifiedS[i] == 'D') y--;
                else if (modifiedS[i] == 'L') x--;
                else x++;
            }

            int distance = abs(x) + abs(y);
            maxDistance = max(maxDistance, distance);
        }
    }

    cout << maxDistance << endl;

    return 0;
}