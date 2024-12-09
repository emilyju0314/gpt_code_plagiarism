#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> hamming_distances(6);

    for(int i = 0; i < 6; i++) {
        cin >> hamming_distances[i];
    }

    int min_length = INT_MAX;
    vector<string> result_strings;

    for(int len = 1; len <= 100000; len++) {
        vector<string> strings(4);

        strings[0] = string(len, 'a');
        strings[1] = string(len, 'a');
        strings[2] = string(len, 'a');
        strings[3] = string(len, 'a');

        int h12 = (len - hamming_distances[4] + hamming_distances[0]) / 2;
        int h13 = len - h12 - hamming_distances[0];
        int h14 = len - hamming_distances[1];
        int h23 = len - hamming_distances[2];
        int h24 = len - hamming_distances[2];
        int h34 = len - hamming_distances[3];

        if(h12 + h13 == len && h12 + h14 == len && h13 + h14 == len && h23 + h24 == len && h23 + h34 == len && h24 + h34 == len) {
            for(int i = 0; i < h12; i++) {
                strings[1][i] = 'b';
                strings[2][i] = 'b';
            }

            for(int i = h12; i < h13 + h12; i++) {
                strings[1][i] = 'b';
                strings[3][i] = 'b';
            }

            for(int i = h13 + h12; i < len; i++) {
                strings[2][i] = 'b';
                strings[3][i] = 'b';
            }

            int total_h = 0;
            for(int i = 0; i < 4; i++) {
                for(int j = i + 1; j < 4; j++) {
                    int h = 0;
                    for(int k = 0; k < len; k++) {
                        if(strings[i][k] != strings[j][k]) {
                            h++;
                        }
                    }
                    total_h += h;
                }
            }

            if(total_h == hamming_distances[0] + hamming_distances[1] + hamming_distances[2] + hamming_distances[3]) {
                if(len < min_length) {
                    min_length = len;
                    result_strings = strings;
                }
            }
        }
    }

    if(min_length == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_length << endl;
        for(string s : result_strings) {
            cout << s << endl;
        }
    }

    return 0;
}