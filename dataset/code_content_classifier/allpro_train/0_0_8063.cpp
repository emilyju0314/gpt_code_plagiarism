#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> proficiency(n);
    for(int i = 0; i < n; i++) {
        cin >> proficiency[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> cards(q);
    for(int i = 0; i < q; i++) {
        int size;
        cin >> size;
        for(int j = 0; j < size; j++) {
            int theorem;
            cin >> theorem;
            cards[i].push_back(theorem);
        }
    }

    double min_avg = 0.0, max_avg = 100.0;
    for(const vector<int>& card : cards) {
        double sum = 0.0;
        for(int theorem : card) {
            sum += proficiency[theorem - 1];
        }
        double card_avg = sum / card.size();
        
        min_avg = max(min_avg, card_avg);
        max_avg = min(max_avg, card_avg);
    }

    double min_prof = 0.0, max_prof = 0.0;
    for(int i = 0; i < n; i++) {
        if(find_if(cards.begin(), cards.end(), [i](const vector<int>& card){
            return find(card.begin(), card.end(), i + 1) != card.end();
        }) == cards.end()) {
            min_prof += proficiency[i];
            max_prof += proficiency[i];
        }
    }

    min_prof /= (n - k);
    max_prof += ((n - k) * 100.0) / (n - k);
    
    cout << fixed;
    cout.precision(10);
    cout << min_prof << " " << max_prof << endl;

    return 0;
}