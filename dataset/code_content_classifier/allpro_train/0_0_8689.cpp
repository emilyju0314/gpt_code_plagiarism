#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sheep {
    int index, l, r;
};

bool compare(Sheep s1, Sheep s2) {
    return s1.l < s2.l;
}

int main() {
    int n;
    cin >> n;

    vector<Sheep> sheeps(n);
    for(int i = 0; i < n; i++) {
        sheeps[i].index = i+1;
        cin >> sheeps[i].l >> sheeps[i].r;
    }

    sort(sheeps.begin(), sheeps.end(), compare);

    vector<int> result(n);
    result[0] = sheeps[0].index;

    for(int i = 1; i < n; i++) {
        result[i] = sheeps[i].index;
        for(int j = i-1; j >= 0; j--) {
            if(sheeps[i].l <= sheeps[j].r) {
                swap(result[i], result[j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}