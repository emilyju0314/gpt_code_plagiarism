#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(vector<int> p1, vector<int> p2) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
}

bool isValidArrangement(vector<vector<int>>& attendants, int K) {
    // Implement the logic to check if it is possible to arrange the flumes
}

double totalLength(vector<vector<int>>& attendants, vector<vector<int>>& flumeArrangement) {
    // Implement the logic to calculate the total length of all flumes
}

double minTotalLength(vector<vector<int>>& attendants, int K) {
    // Implement the recursive function to try different combinations of flume arrangements to minimize the total length
}

int main() {
    int N, K;

    while(cin >> N >> K && (N != 0 || K != 0)) {
        vector<vector<int>> attendants(N, vector<int>(3));

        for(int i = 0; i < N; i++) {
            cin >> attendants[i][0] >> attendants[i][1] >> attendants[i][2];
        }

        double min_length = minTotalLength(attendants, K);

        if(min_length == -1) {
            cout << -1 << endl;
        } else {
            cout << min_length << endl;
        }
    }

    return 0;
}