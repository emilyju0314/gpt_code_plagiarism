#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> sociability(n);
        vector<pair<int, int>> talks;

        for(int i=0; i<n; i++) {
            cin >> sociability[i];
        }

        int max_talks = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int current_talks = min(sociability[i], sociability[j]);
                max_talks = max(max_talks, current_talks);
            }
        }

        for(int i=0; i<n; i++) {
            if(sociability[i] == max_talks) {
                for(int j=i+1; j<n; j++) {
                    if(sociability[j] == max_talks) {
                        talks.push_back({i+1, j+1});
                    }
                }
            }
        }

        cout << talks.size() << endl;
        for(pair<int, int> talk : talks) {
            cout << talk.first << " " << talk.second << endl;
        }
    }

    return 0;
}