#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int m, hit, d;
        cin >> m >> hit >> d;

        vector<string> amidakuji;
        string line;
        for (int i = 0; i < n - 1; i++) {
            cin >> line;
            amidakuji.push_back(line);
        }

        bool hit_reached = false;
        int steps = 0;
        int position = m;
        
        while (steps < d) {
            if (position > 1 && amidakuji[steps][position - 2] == '1') {
                position--;
            } else if (position < n && amidakuji[steps][position - 1] == '1') {
                position++;
            }
            
            if (position == hit) {
                hit_reached = true;
                break;
            }
            
            steps++;
        }

        if (hit_reached) {
            cout << "0" << endl; // Hit reached without drawing a horizontal line
        } else {
            // Try drawing a horizontal line to reach the hit
            for (int i = 0; i < n - 1; i++) {
                if ((position == 1 || amidakuji[i][position - 2] == '0') && 
                    (position == n || amidakuji[i][position - 1] == '0')) {
                    cout << steps + 1 << " " << position << endl;
                    break;
                }
            }
            
            if (!hit_reached) {
                cout << "1" << endl; // Hit cannot be reached even with a horizontal line
            }
        }
    }

    return 0;
}