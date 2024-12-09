#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int previousRating, newRating, highestRank = 1, lowestRank = n;
    bool hasRatingChanged = false, isRated = false;

    for (int i = 0; i < n; i++) {
        std::cin >> previousRating >> newRating;

        if (previousRating != newRating) {
            hasRatingChanged = true;
        }

        if (previousRating < newRating) {
            isRated = true;
        }

        if (i+1 < n && newRating > previousRating) {
            highestRank = i+1;
        }
        
        if (i+1 < n && newRating < previousRating) {
            lowestRank = i+1;
        }
    }

    if (hasRatingChanged) {
        std::cout << "rated" << std::endl;
    } else if (isRated) {
        std::cout << "maybe" << std::endl;
    } else if (highestRank < lowestRank) {
        std::cout << "unrated" << std::endl;
    } else {
        std::cout << "maybe" << std::endl;
    }

    return 0;
}