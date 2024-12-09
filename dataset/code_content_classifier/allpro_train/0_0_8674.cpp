#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> inexperience(N);
        for (int i = 0; i < N; i++) {
            cin >> inexperience[i];
        }

        sort(inexperience.begin(), inexperience.end());

        int groupCount = 0;
        int groupSize = 0;
        for (int i = 0; i < N; i++) {
            groupSize++;
            if (groupSize >= inexperience[i]) {
                groupCount++;
                groupSize = 0;
            }
        }

        cout << groupCount << endl;
    }

    return 0;
}