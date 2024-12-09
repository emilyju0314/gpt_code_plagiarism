#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N-1));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-1; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> paired_city(N, -1);
    vector<bool> is_paired(N, false);

    for(int i=0; i<N; i++) {
        int min_cost = INT_MAX;
        int partner_city = -1;
        for(int j=0; j<N; j++) {
            if(i != j && !is_paired[j] && cost[i][j] < min_cost) {
                min_cost = cost[i][j];
                partner_city = j;
            }
        }
        if(partner_city == -1) {
            cout << -1 << endl;
            return 0;
        }
        paired_city[i] = partner_city;
        is_paired[partner_city] = true;
    }

    for(int i=0; i<N; i++) {
        cout << paired_city[i]+1 << endl;
    }

    return 0;
}