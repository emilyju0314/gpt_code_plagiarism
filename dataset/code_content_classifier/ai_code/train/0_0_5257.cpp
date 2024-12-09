#include <iostream>

using namespace std;

int main() {
    int H1, M1, H2, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;

    int start_time = H1 * 60 + M1; // Convert hours to minutes
    int end_time = H2 * 60 + M2; // Convert hours to minutes

    int study_period = end_time - start_time - K;

    cout << study_period << endl;

    return 0;
}