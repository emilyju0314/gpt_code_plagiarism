#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;

    string visitors;
    cin >> visitors;

    vector<int> adultsIndices;
    for (int i = 0; i < n; i++) {
        if (visitors[i] == '1') {
            adultsIndices.push_back(i);
        }
    }

    int numAdults = adultsIndices.size();
    int minPrice = INT_MAX;

    for (int i = 1; i <= numAdults; i++) {
        int groupSize = (n + i - 1) / i;
        int price = 0;

        for (int j = 0; j < numAdults; j += i) {
            int groupEnd = min(j + i, numAdults);
            
            int groupNumPupils = 0;
            for (int k = j; k < groupEnd; k++) {
                groupNumPupils += adultsIndices[k] - k;
            }

            price += c1 + c2 * (groupSize - 1) * (groupSize - 1) * groupNumPupils;
        }

        minPrice = min(minPrice, price);
    }

    cout << minPrice << endl;

    return 0;
}