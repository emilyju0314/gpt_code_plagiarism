#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int beautyOfSequence(vector<int>& seq) {
    unordered_map<int, int> freq;

    for(int num : seq) {
        freq[num]++;
    }

    vector<int> count;
    for(auto it : freq) {
        count.push_back(it.second);
    }

    sort(count.begin(), count.end(), greater<int>());

    int beauty = count[0];
    for(int i = 1; i < count.size(); i++) {
        if(count[i] >= beauty) {
            beauty = beauty - 1;
        } else {
            beauty = count[i];
        }
    }

    return beauty;
}

int main() {
    int m;
    cin >> m;

    vector<int> sequence(m);
    for(int i = 0; i < m; i++) {
        cin >> sequence[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        vector<int> subsequence(sequence.begin() + l - 1, sequence.begin() + r);
        cout << beautyOfSequence(subsequence) << endl;
    }

    return 0;
}