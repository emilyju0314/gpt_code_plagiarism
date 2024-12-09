#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> groups(n);
    for (int i = 0; i < n; i++) {
        cin >> groups[i];
    }

    int numGroupsOfThree = 0;
    int numOnes = count(groups.begin(), groups.end(), 1);
    int numTwos = count(groups.begin(), groups.end(), 2);

    numGroupsOfThree += min(numOnes, numTwos);

    numOnes -= numGroupsOfThree;
    numTwos -= numGroupsOfThree;

    numGroupsOfThree += numOnes / 3;

    cout << numGroupsOfThree << endl;

    return 0;
}