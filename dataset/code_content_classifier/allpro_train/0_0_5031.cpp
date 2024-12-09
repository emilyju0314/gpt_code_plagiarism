#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Vector {
    int x, y, index;
};

bool compare(Vector vec1, Vector vec2) {
    return abs(vec1.x) + abs(vec1.y) < abs(vec2.x) + abs(vec2.y);
}

int main() {
    int n;
    cin >> n;

    vector<Vector> vectors(n);
    for (int i = 0; i < n; i++) {
        cin >> vectors[i].x >> vectors[i].y;
        vectors[i].index = i + 1;
    }

    sort(vectors.begin(), vectors.end(), compare);

    int min_sum = abs(vectors[0].x + vectors[1].x) + abs(vectors[0].y + vectors[1].y);
    int result_i = vectors[0].index, result_j = vectors[1].index;
    int result_k1 = (vectors[0].x > 0) ? 1 : 2;
    int result_k2 = (vectors[0].y > 0) ? 1 : 3;

    for (int i = 1; i < n - 1; i++) {
        int sum = abs(vectors[i].x + vectors[i+1].x) + abs(vectors[i].y + vectors[i+1].y);
        if (sum < min_sum) {
            min_sum = sum;
            result_i = vectors[i].index;
            result_j = vectors[i+1].index;
            result_k1 = (vectors[i].x > 0) ? 1 : 2;
            result_k2 = (vectors[i].y > 0) ? 1 : 3;
        }
    }

    cout << result_i << " " << result_k1;
    cout << " " << result_j << " " << result_k2 << endl;

    return 0;
}