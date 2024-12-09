#include <iostream>
#include <map>
#include <vector>

using namespace std;

int calculatePoints(map<char, int>& cardPoints, vector<int>& multipliers, vector<string>& hands) {
    int points = 0;
    for (string hand : hands) {
        int basicPoints = 0;
        for (int i = 0; i < 5; i++) {
            char card = hand[i * 2];
            basicPoints += cardPoints[card];
        }
        points += basicPoints * multipliers[basicPoints];
    }
    return points;
}

int main() {
    map<char, int> cardPoints;
    vector<int> multipliers;
    
    while (cin.peek() != EOF) {
        int N;
        cin >> N;
        
        for (char suit : {'S', 'C', 'H', 'D'}) {
            for (int i = 1; i <= 13; i++) {
                cin >> cardPoints[{char('0' + i), suit}];
            }
        }
        
        multipliers.clear();
        for (int i = 0; i < 9; i++) {
            int multiplier;
            cin >> multiplier;
            multipliers.push_back(multiplier);
        }
        
        vector<string> hands(N);
        for (int i = 0; i < N; i++) {
            cin >> hands[i];
        }
        
        int points = calculatePoints(cardPoints, multipliers, hands);
        cout << points << endl;
        if (cin.peek() == EOF) {
            break;
        }
        cin.ignore(); // consume blank line between test cases
    }
    
    return 0;
}