#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, l;
        cin >> n >> l;

        vector<int> flags(n);
        for(int i = 0; i < n; i++) {
            cin >> flags[i];
        }

        double time = 0;

        double speed1 = 1, speed2 = 1;
        int i = 0, j = n-1;
        double pos1 = 0, pos2 = l;

        while(i <= j) {
            double time_to_reach_flag1 = (flags[i] - pos1) / speed1;
            double time_to_reach_flag2 = (pos2 - flags[j]) / speed2;

            if(time_to_reach_flag1 <= time_to_reach_flag2) {
                time += time_to_reach_flag1;
                pos1 = flags[i];
                speed1++;
                i++;
            } else {
                time += time_to_reach_flag2;
                pos2 = flags[j];
                speed2++;
                j--;
            }
        }

        time += (pos2 - pos1) / (speed1 + speed2);

        cout << fixed;
        cout.precision(15);
        cout << time << endl;
    }

    return 0;
}