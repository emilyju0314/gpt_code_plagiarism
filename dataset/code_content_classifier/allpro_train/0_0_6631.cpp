#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> estimatedRatings(n);
    for (int i = 0; i < n; i++) {
        cin >> estimatedRatings[i];
    }

    int maxRating = 0;
    vector<int> communityRatings(n);

    for (int i = 0; i < n; i++) {
        if (estimatedRatings[i] > maxRating) {
            communityRatings[i] = 1;
            maxRating++;
        } else if (estimatedRatings[i] < maxRating) {
            communityRatings[i] = -1;
            maxRating--;
        } else {
            communityRatings[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << communityRatings[i] << endl;
    }

    return 0;
}