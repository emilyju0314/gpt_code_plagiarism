#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> kleofas_ranks(n);
    for (int i = 0; i < n; i++) {
        cin >> kleofas_ranks[i];
    }

    double expected_rank = 0;

    for (int i = 1; i <= m; i++) {
        double total_rank = 0;

        // Calculate the total rank of all other participants
        for (int j = 1; j <= m; j++) {
            double rank_sum = 0;

            for (int k = 0; k < n; k++) {
                if (j < i && kleofas_ranks[k] >= j) {
                    rank_sum += 1;
                } else if (j > i && kleofas_ranks[k] <= j) {
                    rank_sum += 1;
                }
            }

            total_rank += rank_sum;
        }

        // Calculate the expected rank of Kleofáš
        expected_rank += 1 + total_rank / (m - 1);
    }

    cout << fixed << setprecision(16) << expected_rank / m << endl;

    return 0;
}