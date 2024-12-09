#include <iostream>
#include <vector>

using namespace std;

int n, s;
int count = 0;

void findCombinations(vector<int>& selected, int sum, int last) {
    if(selected.size() == n) {
        if(sum == s) {
            count++;
        }
        return;
    }

    for(int i = last + 1; i <= 100; i++) {
        if(sum + i > s) {
            break;
        }
        selected.push_back(i);
        findCombinations(selected, sum + i, i);
        selected.pop_back();
    }
}

int main() {
    while(cin >> n >> s) {
        if(n == 0 && s == 0) {
            break;
        }

        count = 0;
        vector<int> selected;
        findCombinations(selected, 0, -1);
        cout << count << endl;
    }

    return 0;
}