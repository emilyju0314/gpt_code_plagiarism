#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> sizes(2*N-1);
    for(int i = 0; i < 2*N-1; i++) {
        cin >> sizes[i];
    }

    sort(sizes.begin(), sizes.end());

    int totalTshirts = 0;
    for(int i = 0; i < sizes.size(); i++) {
        int numContestants = sizes[i];
        if(numContestants > C) {
            totalTshirts += C;
        } else {
            totalTshirts += numContestants;
        }
    }

    cout << totalTshirts << endl;

    return 0;
}