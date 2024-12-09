#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> customers(N);
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        customers[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> customers[i][j];
        }
        sort(customers[i].begin(), customers[i].end(), greater<int>());
    }

    long long total_sales = 0;
    int prev_highest_fare = 0;
    for (int i = 0; i < N; i++) {
        int highest_fare = 0;
        for (int fare : customers[i]) {
            if (fare >= prev_highest_fare) {
                highest_fare = fare;
                break;
            }
        }
        total_sales += highest_fare;
        prev_highest_fare = highest_fare;
    }

    cout << total_sales << endl;

    return 0;
}