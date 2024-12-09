#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> folds(n, 0);
    int total_width = n;

    while (q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int pi;
            cin >> pi;

            total_width = n - pi + 1;
            folds[pi - 1] = 1;
        } else {
            int li, ri;
            cin >> li >> ri;
            
            int left_border = 0, right_border = total_width;
            for(int i = 0; i < li; i++) {
                if(folds[i] == 1) {
                    left_border = n - i;
                    total_width = right_border - left_border + 1;
                    break;
                }
            }

            for(int i = n-1; i >= ri; i--) {
                if(folds[i] == 1) {
                    right_border = n - i;
                    total_width = right_border - left_border + 1;
                    break;
                }
            }

            cout << total_width << endl;
        }
    }

    return 0;
}