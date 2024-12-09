#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> warriors(109, 0);

    while(q--) {
        int event, pi, li;
        cin >> event >> pi;

        if(event == 1) {
            warriors[pi]++;
        } else if(event == 2) {
            warriors[pi]--;
        } else {
            cin >> li;

            int count = 0;
            for(int i = 0; i <= 108; i++) {
                if(warriors[i] > 0 && (i | pi) > li) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}