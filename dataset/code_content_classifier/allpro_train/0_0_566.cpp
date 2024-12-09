#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> groupA(n);
    vector<int> groupB(n);

    // Read academic performance levels of students in group A
    for(int i = 0; i < n; i++) {
        cin >> groupA[i];
    }

    // Read academic performance levels of students in group B
    for(int i = 0; i < n; i++) {
        cin >> groupB[i];
    }

    vector<int> groupAcount(6, 0);
    vector<int> groupBcount(6, 0);

    // Count the number of students in each group with each academic performance level
    for(int i = 0; i < n; i++) {
        groupAcount[groupA[i]]++;
        groupBcount[groupB[i]]++;
    }

    int totalExchanges = 0;

    // Calculate the maximum number of exchanges required for each academic performance level
    for(int i = 1; i <= 5; i++) {
        if((groupAcount[i] + groupBcount[i]) % 2 != 0) {
            cout << "-1" << endl;
            return 0;
        }
        totalExchanges += abs(groupAcount[i] - groupBcount[i]) / 2;
    }

    cout << totalExchanges / 2 << endl;

    return 0;
}