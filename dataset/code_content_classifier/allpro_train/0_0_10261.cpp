#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int NS, NM, NL, NXL, NXXL;
    cin >> NS >> NM >> NL >> NXL >> NXXL;

    int K;
    cin >> K;

    map<string, int> sizes = {{"S", NS}, {"M", NM}, {"L", NL}, {"XL", NXL}, {"XXL", NXXL}};

    vector<string> optimalSizes(K);
    for (int i = 0; i < K; i++) {
        cin >> optimalSizes[i];
    }

    for (int i = 0; i < K; i++) {
        if (sizes[optimalSizes[i]] > 0) {
            cout << optimalSizes[i] << endl;
            sizes[optimalSizes[i]]--;
        } else {
            if (optimalSizes[i] == "S" && sizes["M"] > 0) {
                cout << "M" << endl;
                sizes["M"]--;
            } else if (optimalSizes[i] == "M" && (sizes["L"] > 0 || sizes["S"] > 0)) {
                if (sizes["L"] > 0) {
                    cout << "L" << endl;
                    sizes["L"]--;
                } else {
                    cout << "S" << endl;
                    sizes["S"]--;
                }
            } else if (optimalSizes[i] == "L" && (sizes["XL"] > 0 || sizes["M"] > 0)) {
                if (sizes["XL"] > 0) {
                    cout << "XL" << endl;
                    sizes["XL"]--;
                } else {
                    cout << "M" << endl;
                    sizes["M"]--;
                }
            } else if (optimalSizes[i] == "XL" && (sizes["XXL"] > 0 || sizes["L"] > 0)) {
                if (sizes["XXL"] > 0) {
                    cout << "XXL" << endl;
                    sizes["XXL"]--;
                } else {
                    cout << "L" << endl;
                    sizes["L"]--;
                }
            } else if (optimalSizes[i] == "XXL" && sizes["XL"] > 0) {
                cout << "XL" << endl;
                sizes["XL"]--;
            }
        }
    }

    return 0;
}