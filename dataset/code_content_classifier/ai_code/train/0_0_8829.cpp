#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> seats(M);
    for(int i = 0; i < M; i++) {
        cin >> seats[i];
    }

    sort(seats.begin(), seats.end());

    int operations = 0;
    int currSeat = N;

    for(int i = M-1; i >= 0; i--) {
        if(seats[i] != currSeat) {
            operations += currSeat - seats[i];
        }
        currSeat = seats[i];
    }

    cout << operations << endl;

    return 0;
}