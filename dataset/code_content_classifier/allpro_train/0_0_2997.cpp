#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
string S;
vector<string> valid_orderings;

bool isValidOrdering(string ordering) {
    int count_A = count(ordering.begin(), ordering.end(), 'A');
    int count_B = count(ordering.begin(), ordering.end(), 'B');
    return count_A == count_B;
}

void generateOrderings(string ordering, int index) {
    if(index == 2*(R+C)) {
        if(isValidOrdering(ordering)) {
            valid_orderings.push_back(ordering);
        }
        return;
    }
    
    if(S[index] == 'A' || S[index] == 'B') {
        generateOrderings(ordering + S[index], index + 1);
    } else {
        generateOrderings(ordering + 'A', index + 1);
        generateOrderings(ordering + 'B', index + 1);
    }
}

int main() {
    cin >> R >> C;
    cin >> S;
    
    generateOrderings("", 0);
    
    int min_unfairness = R - C;
    int count_matching_orderings = 0;
    
    for(string ordering : valid_orderings) {
        int count_A_wins = count(ordering.begin(), ordering.begin() + R, 'A');
        int count_B_wins = count(ordering.begin(), ordering.begin() + R, 'B');
        
        if(abs(count_A_wins - count_B_wins) == min_unfairness) {
            count_matching_orderings++;
        }
    }
    
    cout << count_matching_orderings << endl;
    
    return 0;
}