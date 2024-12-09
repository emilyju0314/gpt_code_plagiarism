#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printResults(bool possible, int A, set<int>& residentVariants) {
    if (possible) {
        cout << "YES" << endl;

        cout << 1 << endl;
        cout << A << endl;

        cout << residentVariants.size() << endl;
        for (int resident : residentVariants) {
            cout << resident << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int A;
    cin >> A;

    set<int> possibleYears;
    vector<int> residents;

    while (A > 1) {
        if (A % 13 == 1) {
            residents.push_back(A / 13);
            A = A / 13 * 12;
        } else if (A % 12 == 0) {
            A = A / 12 * 13;
        } else {
            residents.clear();
            break;
        }
    }

    bool possible = !residents.empty();
    set<int> residentVariants(residents.begin(), residents.end());

    printResults(possible, A, residentVariants);

    return 0;
}