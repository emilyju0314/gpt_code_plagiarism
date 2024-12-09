#include <iostream>
#include <vector>

using namespace std;

// Returns true if there is an obstacle between the candidate and the voter
bool isObstacleBetween(int x1, int y1, int x2, int y2, vector<pair<int, int>>& obstacle) {
    for (int i = 0; i < obstacle.size(); i++) {
        int x3 = obstacle[i].first;
        int y3 = obstacle[i].second;
        int x4 = obstacle[(i + 1) % obstacle.size()].first;
        int y4 = obstacle[(i + 1) % obstacle.size()].second;
        
        int det1 = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
        int det2 = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

        if (det1 * det2 < 0) {
            int det3 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
            int det4 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);

            if (det3 * det4 < 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> obstacles(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;

        for (int j = 0; j < L; j++) {
            int x, y;
            cin >> x >> y;
            obstacles[i].push_back(make_pair(x, y));
        }
    }

    vector<pair<int, int>> voters(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        voters[i] = make_pair(x, y);
    }

    int visibleVoters = 0;

    for (int i = 0; i < M; i++) {
        bool visible = true;
        for (int j = 0; j < N; j++) {
            if (isObstacleBetween(0, 0, voters[i].first, voters[i].second, obstacles[j])) {
                visible = false;
                break;
            }
        }
        if (visible) {
            visibleVoters++;
        }
    }

    cout << visibleVoters << endl;

    return 0;
}