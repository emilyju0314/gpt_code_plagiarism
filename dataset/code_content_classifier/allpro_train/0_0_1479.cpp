#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int w, n, m;
    cin >> w >> n >> m;

    vector<int> registers(n);
    for (int i = 0; i < n; i++) {
        cin >> registers[i];
    }

    vector<string> gates(m);
    for (int i = 0; i < m; i++) {
        cin >> gates[i];
    }

    vector<int> mask(1 << w);
    for (int i = 0; i < (1 << w); i++) {
        mask[i] = 1;
        for (int j = 0; j < w; j++) {
            if (i & (1 << j)) continue;
            mask[i] = 0;
            break;
        }
    }

    for (int k = 0; k < m; k++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int output = 0;
                for (int l = 0; l < w; l++) {
                    int a = registers[i] & (1 << l);
                    int b = registers[j] & (1 << l);
                    switch (gates[k][l]) {
                        case 'A':
                            output |= a & b;
                            break;
                        case 'O':
                            output |= a | b;
                            break;
                        case 'X':
                            output |= a ^ b;
                            break;
                        case 'a':
                            output |= !(a & b);
                            break; 
                        case 'o':
                            output |= !(a | b);
                            break;
                        case 'x':
                            output |= !(a ^ b);
                            break;
                    }
                }
                count += mask[output];
            }
        }
        cout << count << endl;
    }

    return 0;
}