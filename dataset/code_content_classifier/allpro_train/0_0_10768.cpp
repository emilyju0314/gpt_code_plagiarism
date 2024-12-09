#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> genreCount(k+1, 0); // Initialize a vector to count number of movies for each genre
    vector<int> genres(n); // Vector to store the genre of each movie

    for (int i = 0; i < n; i++) {
        cin >> genres[i];
        genreCount[genres[i]]++;
    }
    
    int maxCount = 0;
    int excludedGenre = 1;
    for (int i = 1; i <= k; i++) {
        if (genreCount[i] > maxCount) {
            maxCount = genreCount[i];
            excludedGenre = i;
        }
    }

    cout << excludedGenre << endl;

    return 0;
}