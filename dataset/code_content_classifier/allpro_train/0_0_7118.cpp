#include <iostream>
#include <string>

using namespace std;

int main() {
    string objects;
    cin >> objects;

    int numPostcards = 0;
    int numPhotos = 0;

    for (char c : objects) {
        if (c == 'C') {
            numPostcards++;
        } else {
            numPhotos++;
        }
    }

    int numVisits = 0;
    while (numPostcards > 0 || numPhotos > 0) {
        int postcardsToTake = min(numPostcards, 5);
        numPostcards -= postcardsToTake;

        int photosToTake = min(numPhotos, 5);
        numPhotos -= photosToTake;

        numVisits++;
    }

    cout << numVisits << endl;

    return 0;
}