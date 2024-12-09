#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M == 0 && N == 0) {
            break;
        }

        vector<int> communicationDelay(M);
        for (int i = 0; i < M; i++) {
            cin >> communicationDelay[i];
        }

        int totalDataSent = 0, totalDataReceived = 0;
        map<int, pair<int, int>> playerData;

        for (int i = 0; i < N; i++) {
            int L;
            cin >> L;
            vector<pair<int, pair<int, string>>> submissions(L);
            for (int j = 0; j < L; j++) {
                int P, T;
                string A;
                cin >> P >> T >> A;
                submissions[j] = make_pair(P, make_pair(T, A));
            }

            int dataSent = 0, dataReceived = 0;
            for (auto submission : submissions) {
                int playerID = submission.first;
                if (T + communicationDelay[playerID] <= 19999) {
                    dataReceived += submission.second.size();
                    if (submission.second != "x") {
                        dataSent += submission.second.size();
                    }
                }
            }

            totalDataSent += dataSent;
            totalDataReceived += dataReceived;
            playerData[i] = make_pair(dataSent, dataReceived);
        }

        cout << totalDataSent << " " << totalDataReceived << endl;
        for (int i = 0; i < M; i++) {
            cout << playerData[i].first << " " << playerData[i].second << endl;
        }
        cout << endl;
    }

    return 0;
}