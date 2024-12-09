#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    // Sort A, B, C in ascending order
    int sizes[3] = {A, B, C};
    sort(sizes, sizes + 3);

    // The smallest difference will be when the blocks form a cube
    int side1 = sizes[0];
    int side2 = sizes[1];
    int side3 = sizes[2];

    // The minimum difference will be the volume of the cube where the blocks are painted the same color (side2 - side1) * (side3 - side2)
    int minDiff = (side2 - side1) * (side3 - side2);

    cout << minDiff << endl;

    return 0;
}