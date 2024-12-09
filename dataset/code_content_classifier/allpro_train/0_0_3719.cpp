#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Dish {
    string name;
    int limit;
    int time;
};

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<Dish> menu(N);
        for (int i = 0; i < N; i++) {
            cin >> menu[i].name >> menu[i].limit >> menu[i].time;
        }

        queue<pair<int, vector<string>>> orders;
        for (int i = 0; i < M; i++) {
            int T, K;
            cin >> T >> K;
            vector<string> dishes(K);
            for (int j = 0; j < K; j++) {
                cin >> dishes[j];
            }
            orders.push({T, dishes});
        }

        vector<int> completionTimes(M);
        unordered_map<string, int> dishTimes;

        for (int i = 0; i < M; i++) {
            for (string dish : orders.front().second) {
                dishTimes[dish]++;
            }

            int currentTime = orders.front().first;
            int cookingTime = 0;

            for (int j = 0; j < N; j++) {
                if (dishTimes[menu[j].name] > 0) {
                    int numToCook = min(menu[j].limit, dishTimes[menu[j].name]);
                    dishTimes[menu[j].name] -= numToCook;
                    cookingTime = max(cookingTime, numToCook * menu[j].time);
                }
            }

            completionTimes[i] = currentTime + cookingTime;
            orders.pop();
        }

        for (int i = 0; i < M; i++) {
            cout << completionTimes[i] << endl;
        }
        cout << endl;
    }

    return 0;
}