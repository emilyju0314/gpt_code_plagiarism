#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> power(n);
    vector<int> school(n);
    for(int i = 0; i < n; i++) {
        cin >> power[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> school[i];
    }

    vector<int> chosenOnes(k);
    for(int i = 0; i < k; i++) {
        cin >> chosenOnes[i];
    }
    
    vector<int> maxPower(m + 1, 0);
    for(int i = 0; i < n; i++) {
        maxPower[school[i]] = max(maxPower[school[i]], power[i]);
    }

    int schoolsNeeded = 0;
    for(int i = 0; i < k; i++) {
        if(power[chosenOnes[i]-1] < maxPower[school[chosenOnes[i]-1]]) {
            schoolsNeeded++;
        }
    }

    cout << schoolsNeeded << endl;

    return 0;
}