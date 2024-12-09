#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int currRating = 0;
    bool isPossible = true;
    bool inFirstDivision = false;

    for (int i = 0; i < n; i++) {
        int change, division;
        cin >> change >> division;

        if (currRating == 1900 && division == 1) {
            inFirstDivision = true;
        }

        if (change > 0) {
            currRating += change;
        } else if (change < 0) {
            if (currRating + change < 1900) {
                if (inFirstDivision && division == 2) {
                    isPossible = false;
                } else {
                    currRating += change;
                }
            } else {
                currRating += change;
            }
        }

        if (currRating < 1900 && inFirstDivision) {
            isPossible = false;
        }

    }

    if (!isPossible) {
        cout << "Impossible" << endl;
    } else if (currRating < 1900) {
        cout << "Infinity" << endl;
    } else {
        cout << currRating << endl;
    }

    return 0;
}