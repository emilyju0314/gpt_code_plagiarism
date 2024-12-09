#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Train {
    int cars;
    int departure;
    int arrival;
};

bool compareTrains(const Train& train1, const Train& train2) {
    return train1.arrival < train2.arrival;
}

int main() {
    int NAB, NBA;
    cin >> NAB >> NBA;

    vector<Train> trainsAB(NAB);
    vector<Train> trainsBA(NBA);

    for (int i = 0; i < NAB; i++) {
        cin >> trainsAB[i].cars >> trainsAB[i].departure >> trainsAB[i].arrival;
    }

    for (int i = 0; i < NBA; i++) {
        cin >> trainsBA[i].cars >> trainsBA[i].departure >> trainsBA[i].arrival;
    }

    sort(trainsAB.begin(), trainsAB.end(), compareTrains);
    sort(trainsBA.begin(), trainsBA.end(), compareTrains);

    vector<bool> usedA(NAB, false);
    vector<bool> usedB(NBA, false);

    int transferred = 0;
    int currentA = 0, currentB = 0;

    while (currentA < NAB && currentB < NBA) {
        if (!usedA[currentA] && !usedB[currentB]) {
            if (trainsAB[currentA].arrival <= trainsBA[currentB].departure) {
                transferred += trainsAB[currentA].cars;
                usedA[currentA] = true;
                currentA++;
            } else {
                currentB++;
            }
        } else if (usedA[currentA]) {
            currentA++;
        } else {
            currentB++;
        }
    }

    cout << transferred << endl;

    return 0;
}