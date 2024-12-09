#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string level;
        cin >> level;

        int sheepCount = 0;
        int prevSheepIndex = -1;
        int moves = 0;

        for(int i = 0; i < n; i++) {
            if(level[i] == '*') {
                sheepCount++;
                if(prevSheepIndex == -1) {
                    prevSheepIndex = i;
                } else {
                    moves += (i - prevSheepIndex - 1);
                    prevSheepIndex++;
                }
            }
        }

        cout << moves << endl;
    }

    return 0;
}