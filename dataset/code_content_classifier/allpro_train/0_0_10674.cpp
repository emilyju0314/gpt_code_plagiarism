#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Animal {
    int A, B, C;
    int strength;
    int consecutiveWins;

    Animal(int a, int b, int c) {
        A = a;
        B = b;
        C = c;
        strength = A;
        consecutiveWins = 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Animal> animals;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        animals.push_back(Animal(a, b, c));
    }

    int currentKing = 0;
    int fights = 0;

    while (true) {
        int challenger = currentKing + 1;
        fights++;

        // Fight between current king and challenger
        if (animals[challenger].strength < animals[currentKing].strength) {
            animals[challenger].consecutiveWins++;
            if (animals[challenger].consecutiveWins == 3) {
                cout << challenger << " " << fights << endl;
                return 0;
            }

            currentKing = challenger;
        } else {
            animals[currentKing].consecutiveWins = 0;
            animals[currentKing].strength = animals[currentKing].B;

            animals.push_back(animals[currentKing]);
            currentKing = animals.size() - 1;
        }

        if (currentKing == 0) {
            cout << "-1 -1" << endl;
            return 0;
        }
    }

    return 0;
}