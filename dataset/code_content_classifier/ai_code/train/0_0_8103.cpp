#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> crushes(n);
    for(int i = 0; i < n; i++) {
        cin >> crushes[i];
    }

    int answer = -1;
    for(int t = 1; t <= n; t++) {
        bool valid = true;
        for(int i = 0; i < n; i++) {
            int current = i;
            for(int j = 0; j < t; j++) {
                current = crushes[current] - 1;
            }
            if(current != i) {
                valid = false;
                break;
            }
        }
        if(valid) {
            answer = t;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}