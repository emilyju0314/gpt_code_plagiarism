#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int datasets;
    cin >> datasets;

    while(datasets--) {
        vector<int> gatesHand(9);
        vector<int> jackieHand(9);

        for(int i = 0; i < 9; i++) {
            cin >> gatesHand[i];
        }

        for(int i = 0; i < 9; i++) {
            cin >> jackieHand[i];
        }

        sort(gatesHand.begin(), gatesHand.end());
        sort(jackieHand.begin(), jackieHand.end());

        int totalPossibilities = 0;
        int gatesWins = 0;
        int jackieWins = 0;

        do {
            do {
                int gatesScore = 0;
                int jackieScore = 0;

                for(int i = 0; i < 9; i++) {
                    if(gatesHand[i] > jackieHand[i]) {
                        gatesScore += gatesHand[i] + jackieHand[i];
                    } else if(gatesHand[i] < jackieHand[i]) {
                        jackieScore += gatesHand[i] + jackieHand[i];
                    }
                }

                if(gatesScore > jackieScore) {
                    gatesWins++;
                } else {
                    jackieWins++;
                }

                totalPossibilities++;
            } while(next_permutation(jackieHand.begin(), jackieHand.end()));
        } while(next_permutation(gatesHand.begin(), gatesHand.end()));

        double gatesProbability = (double)gatesWins / totalPossibilities;
        double jackieProbability = (double)jackieWins / totalPossibilities;

        cout << fixed << setprecision(5) << gatesProbability << " " << jackieProbability << endl;
    }

    return 0;
}