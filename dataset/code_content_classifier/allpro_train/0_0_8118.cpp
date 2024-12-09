#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int B, W;
    cin >> B >> W;

    vector<int> probabilities(B+W+1);

    probabilities[1] = 500000004; // Probability on the 1st step

    for(int i = 2; i <= B+W; i++) {
        probabilities[i] = probabilities[i-1];
    }

    for(int i = 1; i <= B+W; i++) {
        cout << probabilities[i] << endl;
    }

    return 0;
}