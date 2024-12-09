#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> enter(n);
    vector<int> exit(n);

    for(int i = 0; i < n; i++) {
        cin >> enter[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> exit[i];
    }

    unordered_map<int, int> enterIndex;
    for(int i = 0; i < n; i++) {
        enterIndex[exit[i]] = i;
    }

    int currMaxIndex = -1;
    int finedCars = 0;

    for(int i = 0; i < n; i++) {
        currMaxIndex = max(currMaxIndex, enterIndex[enter[i]]);
        if(i < currMaxIndex) {
            finedCars++;
        }
    }

    cout << finedCars << endl;

    return 0;
}