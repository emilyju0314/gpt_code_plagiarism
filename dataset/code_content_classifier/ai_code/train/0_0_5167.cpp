#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int m;
    cin >> m;

    unordered_map<int, int> frequency;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        char plus;
        char slash;

        cin >> a >> plus >> b >> slash >> c;

        int coordinate = (a + b) / c;
        frequency[coordinate]++;
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        char plus;
        char slash;

        cin >> a >> plus >> b >> slash >> c;

        int coordinate = (a + b) / c;
        cout << frequency[coordinate] << " ";
    }

    return 0;
}