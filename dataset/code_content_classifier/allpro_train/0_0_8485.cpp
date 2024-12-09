#include <iostream>
#include <vector>

using namespace std;

bool isSmallerSequence(vector<int>& seq1, vector<int>& seq2) {
    int m = min(seq1.size(), seq2.size());
    for (int i = 0; i < m; i++) {
        if (seq1[i] < seq2[i]) {
            return true;
        } else if (seq1[i] > seq2[i]) {
            return false;
        }
    }
    return seq1.size() < seq2.size();
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int maxVal = a[0];
    vector<int> maxSeq = {1};

    for (int i = 0; i < (1 << N); i++) {
        vector<int> subSeq;
        int val = 1;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                subSeq.push_back(j + 1);
                val *= a[j];
            }
        }
        if (val > maxVal || (val == maxVal && isSmallerSequence(subSeq, maxSeq))) {
            maxVal = val;
            maxSeq = subSeq;
        }
    }

    cout << maxSeq.size() << endl;
    for (int i = 0; i < maxSeq.size(); i++) {
        cout << maxSeq[i] << endl;
    }

    return 0;
}