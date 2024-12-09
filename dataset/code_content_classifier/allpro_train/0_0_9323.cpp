#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chosen_points(n);
    for(int i = 0; i < n; i++) {
        cin >> chosen_points[i];
    }

    vector<int> result(n, -1);

    for(int i = 0; i < n; i++) {
        if(chosen_points[i] % 2 == 0) {
            result[i * 2] = chosen_points[i];
        } else {
            result[(i * 2 + 1) % (2 * n)] = chosen_points[i];
        }
    }

    int next = 0;
    for(int i = 0; i < n; i++) {
        if(result[i] == -1) {
            while(chosen_points[next] % 2 == 0 || chosen_points[next] == chosen_points[(next + 1) % n]) {
                next++;
            }
            result[i] = chosen_points[next];
            next++;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}