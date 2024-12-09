#include <iostream>
#include <vector>

using namespace std;

int main() {
    int f;
    cin >> f;

    vector<int> sides(f);
    int total_sides = 0;
    for (int i = 0; i < f; i++) {
        cin >> sides[i];
        total_sides += sides[i];
    }

    int total_vertices = total_sides - f + 2;
    cout << total_vertices << endl;

    int vertex = 1;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < sides[i]; j++) {
            cout << vertex << " ";
            vertex++;
        }
        cout << endl;
    }

    return 0;
}