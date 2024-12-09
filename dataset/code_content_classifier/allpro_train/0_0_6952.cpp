#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    // Read the exam scores of the students
    vector<int> scores(n);
    vector<int> freq(6, 0); // Frequency of each score from 0 to 5
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        scores[i] = score;
        freq[score]++;
    }

    // Initialize the min and max scholarship values for each score
    int k3 = 0, k4 = 0, k5 = 0;

    // Distribute the scholarships optimally
    k5 = s / n; // Distribute the budget evenly among all students
    if (freq[5] * k5 > s) {
        k5 = s / freq[5]; // Adjust k5 if the total budget exceeds s
    }

    int remaining = s - freq[5] * k5;
    if (freq[4] > 0) {
        k4 = remaining / freq[4]; // Calculate k4 based on remaining budget and frequency of score 4
    }

    remaining -= freq[4] * k4;
    if (freq[3] > 0) {
        k3 = remaining / freq[3]; // Calculate k3 based on remaining budget and frequency of score 3
    }

    // Check if the distribution follows the rules
    if (k3 <= k4 && k4 <= k5) {
        cout << k3 << " " << k4 << " " << k5 << endl;
    } else {
        cout << -1 << endl; // If no optimal answer is found
    }

    return 0;
}