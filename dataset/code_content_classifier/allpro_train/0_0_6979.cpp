#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    int smallest = 101;
    int largest = 0;

    cin >> n >> m;

    vector<int> flats(101, -1);

    for (int i = 0; i < m; i++) {
        int k, f;
        cin >> k >> f;
        flats[k] = f;

        smallest = min(smallest, f);
        largest = max(largest, f);
    }

    int possibleFloors = 0;
    for (int j = smallest; j <= largest; j++) {
        int cnt = 0;
        for (int i = 1; i <= 100; i++) {
            if (flats[i] != -1 && (i - 1) / j != flats[i] - 1) {
                break;
            } else {
                cnt++;
            }
        }

        if (cnt == 100) {
            possibleFloors++;
        }
    }

    if(possibleFloors == 1){
        for (int j = smallest; j <= largest; j++) {
            int cnt = 0;
            for (int i = 1; i <= 100; i++) {
                if (flats[i] != -1 && (i - 1) / j != flats[i] - 1) {
                    break;
                } else {
                    cnt++;
                }
                if(cnt == n){
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}