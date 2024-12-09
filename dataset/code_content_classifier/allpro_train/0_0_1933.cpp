#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> frontCount, backCount;

    for(int i = 0; i < n; i++) {
        int front, back;
        cin >> front >> back;

        frontCount[front]++;
        backCount[back]++;
    }

    int maxFrontCount = 0, maxBackCount = 0;

    for(auto& p : frontCount) {
        maxFrontCount = max(maxFrontCount, p.second);
    }

    for(auto& p : backCount) {
        maxBackCount = max(maxBackCount, p.second);
    }

    if(maxFrontCount >= (n+1)/2 || maxBackCount >= (n+1)/2) {
        cout << 0 << endl;
    } else {
        int neededMoves = max((n+1)/2 - maxFrontCount, (n+1)/2 - maxBackCount);
        cout << neededMoves << endl;
    }

    return 0;
}