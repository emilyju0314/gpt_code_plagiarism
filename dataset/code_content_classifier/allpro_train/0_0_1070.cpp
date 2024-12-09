#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Marriage {
    int man;
    int woman;
    int delight;
};

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<Marriage> marriages(k);
    for(int i = 0; i < k; i++) {
        cin >> marriages[i].man >> marriages[i].woman >> marriages[i].delight;
    }

    sort(marriages.begin(), marriages.end(), [](const Marriage& a, const Marriage& b) {
        return a.delight < b.delight;
    });

    vector<bool> used(n+1);
    int count = 0;
    int sum = 0;

    for(const Marriage& marriage : marriages) {
        if(!used[marriage.man] && !used[marriage.woman]) {
            used[marriage.man] = true;
            used[marriage.woman] = true;
            count++;
            sum += marriage.delight;
        }

        if(count == n) {
            break;
        }
    }

    cout << sum << endl;

    return 0;
}