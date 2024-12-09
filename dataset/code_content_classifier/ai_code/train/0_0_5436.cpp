#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<vector<int>> programs(N, vector<int>(3));
    for(int i = 0; i < N; i++) {
        cin >> programs[i][0] >> programs[i][1] >> programs[i][2];
    }

    vector<int> timeline(100005 * 2, 0);
    int recorders = 0;
    set<int> channels;

    for(int i = 0; i < N; i++) {
        int start = programs[i][0] * 2 - 1;
        int end = programs[i][1] * 2 - 1;
        int channel = programs[i][2];

        for(int j = start; j < end; j++) {
            if(timeline[j] == 0) {
                timeline[j] = channel;
                channels.insert(channel);
            } else {
                if(timeline[j] != channel) {
                    recorders++;
                    break;
                }
            }
        }
    }

    cout << recorders + channels.size() << endl;

    return 0;
}