#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> boxes(N);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i];
    }

    int sugimManju = 0, sigmaManju = 0;
    for (int i = 1; i < N; i++) {
        int delta = min(boxes[i-1], boxes[i]);
        sugimManju += delta;
        boxes[i-1] -= delta;
        boxes[i] -= delta;
    }

    for (int i = 0; i < N; i++) {
        sigmaManju += boxes[i];
    }

    cout << sugimManju << " " << sigmaManju << endl;

    return 0;
}