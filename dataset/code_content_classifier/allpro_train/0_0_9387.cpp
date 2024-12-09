#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ratings(n);
    for(int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    vector<int> changes(n);
    for(int i = 1; i < n; i++) {
        changes[i] = changes[i - 1] + i * (n - i);
    }

    vector<int> participantNumbers(n);
    for(int i = 0; i < n; i++) {
        participantNumbers[i] = i + 1;
    }

    int i = 0;
    while(i < n) {
        int minIndex = min_element(ratings.begin(), ratings.end()) - ratings.begin();
        if(changes[minIndex] < k) {
            cout << participantNumbers[minIndex] << endl;
            ratings.erase(ratings.begin() + minIndex);
            changes.erase(changes.begin() + minIndex);
            participantNumbers.erase(participantNumbers.begin() + minIndex);
        } else {
            i++;
        }
    }

    return 0;
}