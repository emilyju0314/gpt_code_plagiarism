#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string findOperationSequence(const vector<int>& target, int p, int q) {
    return "impossible";
}

int main() {
    int t1, t2, t3, t4, t5, t6;

    while (cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6) {
        if (t1 == 0 && t2 == 0 && t3 == 0 && t4 == 0 && t5 == 0 && t6 == 0)
            break;

        int p, q;
        cin >> p >> q;

        vector<int> target = {t1, t2, t3, t4, t5, t6};

        string result = findOperationSequence(target, p, q);
        cout << result << endl;
    }

    return 0;
}