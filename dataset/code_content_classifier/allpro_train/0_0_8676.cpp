#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int R, G, B;
    cin >> R >> G >> B;

    vector<int> red(R);
    for(int i = 0; i < R; i++) {
        cin >> red[i];
    }

    vector<int> green(G);
    for(int i = 0; i < G; i++) {
        cin >> green[i];
    }

    vector<int> blue(B);
    for(int i = 0; i < B; i++) {
        cin >> blue[i];
    }

    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());

    long long max_area = 0;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < G; j++) {
            for(int k = 0; k < B; k++) {
                long long area = (long long)red[i] * green[j] + (long long)green[j] * blue[k] + (long long)blue[k] * red[i];
                max_area = max(max_area, area);
            }
        }
    }

    cout << max_area << endl;

    return 0;
}