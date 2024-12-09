#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cages(N);

    // Ask questions to determine the number of flamingoes in each cage
    for (int i = 0; i < N-1; i += 2) {
        cout << "? " << i+1 << " " << i+2 << endl;
        fflush(stdout);
        cin >> cages[i];
        cout << "? " << i+2 << " " << i+3 << endl;
        fflush(stdout);
        cin >> cages[i+1];
    }

    // Handle case when N is odd
    if (N % 2 != 0) {
        cout << "? " << N << " " << N-1 << endl;
        fflush(stdout);
        cin >> cages[N-1];
    }

    // Calculate the number of flamingoes in each cage
    vector<int> totalFlamingoes(N);
    totalFlamingoes[0] = (cages[0] + cages[1] - cages[N-1]) / 2;
    for (int i = 1; i < N; i++) {
        totalFlamingoes[i] = cages[i-1] - totalFlamingoes[i-1];
    }

    // Output the total number of flamingoes in each cage
    cout << "!";
    for (int i = 0; i < N; i++) {
        cout << " " << totalFlamingoes[i];
    }
    cout << endl;
    fflush(stdout);

    return 0;
}