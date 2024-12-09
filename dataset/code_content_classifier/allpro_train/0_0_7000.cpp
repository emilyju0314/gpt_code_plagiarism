#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

double computeProbability(int N, int M, int L, vector<string>& hand_pattern) {
    map<char, int> rankMap;
    for(int i=0; i<M; i++) {
        char c = 'a' + i;
        rankMap[c] = N;
    }

    double totalCount = 0, validCount = 0;

    vector<int> hand(L, 1);
    while(true) {
        bool isValid = true;
        map<char, int> rankCount;

        for(int i=0; i<L; i++) {
            char pattern = hand_pattern[i][0];
            int plusCount = 0;
            for(char& c : hand_pattern[i]) {
                if(c == '+') plusCount++;
            }

            if(rankCount.find(pattern) == rankCount.end()) {
                rankCount[pattern] = hand[i];
                for(int j=1; j<=plusCount; j++) {
                    rankCount[pattern] += j;
                }
            } else {
                int rank = rankCount[pattern];
                for(int j=1; j<=plusCount; j++) {
                    if(rank + j != hand[i]) {
                        isValid = false;
                        break;
                    }
                }
                rankCount[pattern] = rank;
            }
        }

        if(isValid) validCount++;
        totalCount++;

        bool flag = true;
        for(int i=L-1; i>=0; i--) {
            if(!flag) break;
            if(hand[i] < M) {
                hand[i]++;
                flag = false;
            } else {
                hand[i] = 1;
            }
        }

        if(flag) break;
    }

    return validCount / totalCount;
}

int main() {
    int N, M, L;
    while(true) {
        cin >> N >> M >> L;
        if(N == 0 && M == 0 && L == 0) break;

        vector<string> hand_pattern(L);
        for(int i=0; i<L; i++) {
            cin >> hand_pattern[i];
        }

        double probability = computeProbability(N, M, L, hand_pattern);
        cout << fixed << setprecision(10) << probability << endl;
    }

    return 0;
}