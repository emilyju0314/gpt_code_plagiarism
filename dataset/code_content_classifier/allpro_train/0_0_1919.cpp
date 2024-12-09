#include <iostream>
#include <vector>

using namespace std;

void awardMedals(vector<int>& problems) {
    int n = problems.size();

    int g = 0, s = 0, b = 0;

    // Find the maximum number of participants that can be awarded
    int maxMedals = min(n / 2, n - 1);

    if (maxMedals <= 0) {
        cout << "0 0 0" << endl;
        return;
    }

    // Assigning medals based on the conditions
    int goldIndex = 0, silverIndex = 0, bronzeIndex = 0;

    g = 1;
    int sCount = 0, bCount = 0;
    
    while (sCount < maxMedals && silverIndex < n) {
        sCount++;
        s++;
        silverIndex++;
        while (silverIndex < n && problems[silverIndex] == problems[silverIndex - 1]) {
            silverIndex++;
        }
    }

    while (bCount < maxMedals && bronzeIndex < n) {
        bCount++;
        b++;
        bronzeIndex++;
        while (bronzeIndex < n && problems[bronzeIndex] == problems[bronzeIndex - 1]) {
            bronzeIndex++;
        }
    }

    cout << g << " " << s << " " << b << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> problems(n);
        for (int i = 0; i < n; i++) {
            cin >> problems[i];
        }

        awardMedals(problems);
    }

    return 0;
}