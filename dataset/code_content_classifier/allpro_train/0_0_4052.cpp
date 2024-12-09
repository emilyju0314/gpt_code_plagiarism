#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> count;
    int maxValue = 0;
    int maxCount = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++;

        if (count[num] > maxCount) {
            maxCount = count[num];
            maxValue = num;
        }
    }

    cout << maxCount << endl;

    return 0;
}