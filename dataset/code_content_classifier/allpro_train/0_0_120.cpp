#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<int> booksToRead(m);
    for (int i = 0; i < m; i++) {
        cin >> booksToRead[i];
    }

    int totalWeight = 0;
    for (int i = 0; i < m; i++) {
        int bookNumber = booksToRead[i];
        vector<int> booksAboveX;
        for (int j = 0; j < n; j++) {
            if (j+1 != bookNumber) {
                booksAboveX.push_back(weights[j]);
            }
        }

        sort(booksAboveX.begin(), booksAboveX.end(), greater<int>());
        int liftedWeight = 0;
        for (int j = 0; j < booksAboveX.size(); j++) {
            liftedWeight += booksAboveX[j];
        }

        totalWeight += liftedWeight;
    }

    cout << totalWeight << endl;

    return 0;
}