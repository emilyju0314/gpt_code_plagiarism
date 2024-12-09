#include <iostream>
#include <algorithm>

int main() {
    std::string oleg, igor;
    std::cin >> oleg >> igor;

    std::sort(oleg.begin(), oleg.end());
    std::sort(igor.begin(), igor.end(), std::greater<char>());

    int n = oleg.size();
    std::string name(n, '?');
    int olegIndex = 0, igorIndex = 0;
    bool olegTurn = true;

    for (int i = 0; i < n; i++) {
        if (olegTurn) {
            name[i] = oleg[olegIndex];
            olegIndex++;
            olegTurn = false;
        } else {
            name[i] = igor[igorIndex];
            igorIndex++;
            olegTurn = true;
        }
    }

    std::cout << name << std::endl;

    return 0;
}