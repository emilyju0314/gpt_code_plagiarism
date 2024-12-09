#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Biddle {
    string name;
    int cost, vocal, dance, looks;
};

int main() {
    int N, M;

    while (cin >> N >> M) {
        vector<Biddle> bidle_list(N);

        for (int i = 0; i < N; i++) {
            cin.ignore();
            getline(cin, bidle_list[i].name);
            cin >> bidle_list[i].cost >> bidle_list[i].vocal >> bidle_list[i].dance >> bidle_list[i].looks;
        }

        int max_rank = 0;

        for (int i = 0; i < (1 << N); i++) {
            int total_cost = 0;
            int total_vocal = 0, total_dance = 0, total_looks = 0;
            int rank = 0;

            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    total_cost += bidle_list[j].cost;
                    total_vocal += bidle_list[j].vocal;
                    total_dance += bidle_list[j].dance;
                    total_looks += bidle_list[j].looks;
                    rank = max({total_vocal, total_dance, total_looks});
                }
            }

            if (total_cost <= M) {
                max_rank = max(max_rank, rank);
            }
        }

        cout << max_rank << endl;
    }

    return 0;
}